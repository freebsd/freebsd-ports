# New ports collection makefile for:	dspam
# Date created:			3 August 2003
# Whom:				Dominic Marks <dom@wirespeed.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dspam
PORTVERSION=	2.8.3
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	rob@debank.tv
COMMENT=	A server-side bayesian spam filter

USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-userdir=${PREFIX}/etc/dspam
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g'

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL=""
SED_SCRIPT+=	-e 's,%%MYSQL%%,,g'
.else
LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=	--with-db4-includes=${LOCALBASE}/include/db41
PLIST_SUB+=	DB4=""
PLIST_SUB+=	MYSQL="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
.endif

.if defined(WITH_MAILDROP)
RUN_DEPENDS=	maildrop:${PORTSDIR}/mail/maildrop
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/bin/maildrop $u'
.endif

.if defined(WITH_PROCMAIL)
RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/bin/procmail $u'
.endif

.if defined(WITH_QMAIL)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
.endif

.if defined(ENABLE_SPAM_DELIVERY)
CONFIGURE_ARGS+=	--enable-spam-delivery
.endif

DOCS=		CHANGE README

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBTOOLFLAGS%%|${LIBTOOLFLAGS}|g ; \
		s|-ldb-4.1|-ldb41|g' ${WRKSRC}/configure

post-install:
.if defined(WITH_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/tools.mysql_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mysql.data ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${SED} ${SED_SCRIPT} ${PKGMESSAGE}

.include <bsd.port.mk>
