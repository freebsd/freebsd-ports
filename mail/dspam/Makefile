# New ports collection makefile for:	dspam
# Date created:			3 August 2003
# Whom:				Dominic Marks <dom@wirespeed.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dspam
PORTVERSION=	2.8.1
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	rob@debank.tv
COMMENT=	A server-side bayesian spam filter

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-userdir=${PREFIX}/etc/dspam
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
PLIST_SUB+=	DB4="@comment "
.else
LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=	--with-db4-includes=${LOCALBASE}/include/db41
PLIST_SUB+=	DB4=""
.endif

.if defined(WITH_MAILDROP)
RUN_DEPENDS=	maildrop:${PORTSDIR}/mail/maildrop
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/bin/maildrop $u'
.endif

.if defined(WITH_PROCMAIL)
RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/bin/procmail $u'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBTOOLFLAGS%%|${LIBTOOLFLAGS}|g ; \
		s|-ldb-4.1|-ldb41|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/CHANGE \
		${DOCSDIR}
.endif
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
