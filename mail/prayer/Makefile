# $FreeBSD$

PORTNAME=	prayer
PORTVERSION=	1.3.5
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Prayer Webmail System

LICENSE=	GPLv2

LIB_DEPENDS=	c-client4:${PORTSDIR}/mail/cclient

USE_PERL5_BUILD=yes
USES=		iconv shebangfix gmake
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	utils/ucsnews.pl \
		templates/old/make_olist.pl \
		templates/src/*.pl

MAKE_ENV+=	PORTCFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		PORTLDFLAGS="${LDFLAGS}"

PORTDOCS=	ACCOUNTD CMD_LINE DESIGN DONE DONE-OLD FEATURES ICONLIST \
		INSTALL LOGS NOTICE README ROADMAP SECURITY TODO

USE_RC_SUBR=	prayer

OPTIONS_DEFINE=	SESSIONCACHE TIDY SSL LDAP DOCS
OPTIONS_DEFAULT=	SESSIONCACHE TIDY SSL LDAP

SESSIONCACHE_DESC=	Activate Session Cache

USERS=		_prayer
GROUPS=		prayer

MAN5=		prayer.cf.5
MAN8=		prayer-session.8 prayer-ssl-prune.8 prayer.8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSESSIONCACHE}
USE_BDB=	yes
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
.endif

.if ${PORT_OPTIONS:MTIDY}
LIB_DEPENDS+=	tidy-0.99.0:${PORTSDIR}/www/tidy-lib
.endif

pre-patch:
	@${CP} ${WRKSRC}/defaults/Config ${WRKSRC}/Config

post-patch:
# correct chroot
	@${REINPLACE_CMD} "s#\"/chroot/prayer\"#config->var_prefix#" ${WRKSRC}/servers/prayer_chroot.c
# change the user in the default config and cylog util
	@${REINPLACE_CMD} "s#prayer_user           = \"prayer\"#prayer_user           = \"_prayer\"#" ${WRKSRC}/files/etc/prayer.cf.SRC
	@${REINPLACE_CMD} "s#\"prayer\" \"prayer\"#\"_prayer\" \"prayer\"#" ${WRKSRC}/utils/prayer-cyclog.SRC
	@${REINPLACE_CMD} "/^CC\s.*/d" ${WRKSRC}/Config
	@${REINPLACE_CMD} "s#%%PREFIX%%#${PREFIX}#" ${WRKSRC}/Config

post-configure:
.if ${PORT_OPTIONS:MSESSIONCACHE}
	@${REINPLACE_CMD} "s|^#DB_INCLUDE=.*|DB_INCLUDE=-I${BDB_INCLUDE_DIR}|" ${WRKSRC}/Config
	@${REINPLACE_CMD} "s|^#DB_LIBS=.*|DB_LIBS=-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}|" ${WRKSRC}/Config
.else
	@${REINPLACE_CMD} "s#^SESSION_CACHE_ENABLE = true#SESSION_CACHE_ENABLE = false#" ${WRKSRC}/Config
.endif
	@${REINPLACE_CMD} "s#^RW_USER    = prayer#RW_USER    = _prayer#" ${WRKSRC}/Config

.if ${PORT_OPTIONS:MSSL}
	@${REINPLACE_CMD} "s#CCLIENT_SSL_ENABLE   = false#CCLIENT_SSL_ENABLE   = true#" ${WRKSRC}/Config
.else
	@${REINPLACE_CMD} "s#^SSL_ENABLE           = true#SSL_ENABLE           = false#" ${WRKSRC}/Config
.endif

.if ! ${PORT_OPTIONS:MLDAP}
	@${REINPLACE_CMD} "s#LDAP_ENABLE          = true#LDAP_ENABLE          = false#" ${WRKSRC}/Config
.endif

.if ! ${PORT_OPTIONS:MTIDY}
	@${REINPLACE_CMD} "s#TIDY_ENABLE          = true#TIDY_ENABLE          = false#" ${WRKSRC}/Config
.else
	@${REINPLACE_CMD} "s#TIDY_INCLUDE=-I/usr/include/tidy#TIDY_INCLUDE=-I${LOCALBASE}/include/tidy#" ${WRKSRC}/Config
.endif

pre-install:
	@${MKDIR} ${PREFIX}/etc/prayer

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
