# New ports collection makefile for:	dspam
# Date created:			3 August 2003
# Whom:				Dominic Marks <dom@wirespeed.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dspam
PORTVERSION=	2.10.6
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	rob@debank.tv
COMMENT=	A server-side bayesian spam filter

OPTIONS=	MYSQL "Use MySQL and not db4 as database" off \
		MYSQL_COMPRESS "Compress dspam <--> MySQL" off \
		MAILDROP "Use Maildrop as local delivery agent" off \
		PROCMAIL "Use Procmail as local delivery agent" off \
		SENDMAIL_LDA "Use Sendmail as local delivery agent" off \
		SENDMAIL "Play nice with sendmail server" off \
		QMAIL "Play nice with Qmail mail server" off \
		ENABLE_SPAM_DELIVERY "Deliver messages marked as spam" off \
		SIGNATURE_HEADERS "Put signatures in the header" off \
		WHITELIST "Automatic whitelisting of ham" off \
		OPT_IN  "Enable opt in" off \
		TRUSTED_USERS "Disable trusted user security" off \
		TUM "Enables TuM (Train until Mature)" off \
		ALT_BAYESIAN "Enable alternative-bayesian" on \
		NO_BIAS "Disable bias" off \
		VIRT_USERS "Enable virtual users (needs MYSQL)" off \
		SAT "Enable spam source address logging" off \
		VERBOSE_DEBUG "Enable verbose debug" off

USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g'

WITH_SIGNATURE_LIFE?=	28

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL=""
SED_SCRIPT+=	-e 's,%%MYSQL%%,,g'
.else
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=	--with-db4-includes=${LOCALBASE}/include/db41
PLIST_SUB+=	DB4=""
PLIST_SUB+=	MYSQL="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
.endif

.if defined(WITH_MYSQL_COMPRESS)
CONFIGURE_ARGS+=	--enable-client-compression
.endif

.if defined(DSPAM_USERDIR)
CONFIGURE_ARGS+=--with-userdir=${DSPAM_USERDIR}
.else
CONFIGURE_ARGS+=--with-userdir=${PREFIX}/etc/dspam
.endif

.if defined(WITH_MAILDROP)
RUN_DEPENDS+=	maildrop:${PORTSDIR}/mail/maildrop
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/bin/maildrop $u'
.endif

.if defined(WITH_PROCMAIL)
RUN_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/bin/procmail $u'
.endif

.if defined(WITH_SENDMAIL_LDA) && exists(/usr/sbin/sendmail)
CONFIGURE_ARGS+=	--with-local-delivery-agent=/usr/sbin/sendmail
.else
.if defined(WITH_SENDMAIL_LDA) && exists(${LOCALBASE}/sbin/sendmail)
CONFIGURE_ARGS+=	--with-local-delivery-agent='${LOCALBASE}/sbin/sendmail'
.endif
.endif

.if defined(WITH_SENDMAIL)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
.endif

.if defined(WITH_QMAIL)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
.endif

.if defined(WITH_SIGNATURE_LIFE)
CONFIGURE_ARGS+=	--with-signature-life=${WITH_SIGNATURE_LIFE}
.endif

.if defined(WITH_ENABLE_SPAM_DELIVERY)
CONFIGURE_ARGS+=	--enable-spam-delivery
.endif

.if defined(WITH_SIGNATURE_HEADERS)
CONFIGURE_ARGS+=	--enable-signature-headers
.endif

.if defined(WITH_WHITELIST)
CONFIGURE_ARGS+=	--enable-whitelist
.endif

.if defined(WITH_OPT_IN)
CONFIGURE_ARGS+=	--enable-opt-in
.endif

.if defined(WITH_TRUSTED_USERS)
CONFIGURE_ARGS+=	--disable-trusted-user-security
.endif

.if defined(WITH_TUM)
CONFIGURE_ARGS+=	--enable-tum
.endif

.if defined(WITH_ALT_BAYESIAN)
CONFIGURE_ARGS+=	--enable-alternative-bayesian
.endif

.if defined(WITH_NO_BIAS)
CONFIGURE_ARGS+=	--disable-bias
.endif

.if defined(WITH_VIRT_USERS)
CONFIGURE_ARGS+=	--enable-virtual-users
.endif

.if defined(WITH_SAT)
CONFIGURE_ARGS+=	--enable-source-address-tracking
.endif

.if defined(WITH_VERBOSE_DEBUG)
CONFIGURE_ARGS+=	--enable-verbose-debug
.endif

DOCS=		CHANGE README

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBTOOLFLAGS%%|${LIBTOOLFLAGS}|g ; \
		s|-ldb-4.1|-ldb41|g' ${WRKSRC}/configure

pre-configure:
.if defined(WITH_MAILDROP) && (defined(WITH_PROCMAIL) || defined(WITH_SENDMAIL_LDA))
	@${ECHO_CMD} "You can only use one local delivery agent at once."
	@${FALSE}
.endif
.if defined(WITH_PROCMAIL) && (defined(WITH_MAILDROP) || defined(WITH_SENDMAIL_LDA))
	@${ECHO_CMD} "You can only use one local delivery agent at once."
	@${FALSE}
.endif
.if !defined(WITH_MYSQL) && (defined(WITH_MYSQL_COMPRESS) || defined(WITH_VIRT_USERS))
	@${ECHO_CMD} "You need MySQL support to use this feature."
	@${FALSE}
.endif

post-install:
.if defined(WITH_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/tools.mysql_drv && \
		${INSTALL_DATA} README *.sql* ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mysql.data ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${SED} ${SED_SCRIPT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
