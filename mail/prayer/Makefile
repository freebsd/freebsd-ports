# New ports collection makefile for:    prayer
# Date created:         27 Dez 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	prayer
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Prayer Webmail System

LIB_DEPENDS=	c-client4.9:${PORTSDIR}/mail/cclient

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_ICONV=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	PORTCFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		PORTLDFLAGS="${LDFLAGS}"

PORTDOCS=	ACCOUNTD CMD_LINE DESIGN DONE DONE-OLD FEATURES ICONLIST \
		INSTALL LOGS NOTICE README ROADMAP SECURITY TODO

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENCE

USE_RC_SUBR=	prayer

OPTIONS=	SESSIONCACHE	"Activate Session Cache" On \
		TIDY	"Enable tidy support" On \
		SSL	"Enable SSL support" On \
		LDAP	"Enable LDAP support" On

USERS=		_prayer
GROUPS=		prayer

MAN5=		prayer.cf.5
MAN8=		prayer-session.8 prayer-ssl-prune.8 prayer.8

.include <bsd.port.pre.mk>

.if defined(WITH_SESSIONCACHE)
USE_BDB=	yes
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
.endif

.if !defined(WITHOUT_TIDY)
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

post-configure:
	@${REINPLACE_CMD} "s#%%PREFIX%%#${PREFIX}#" ${WRKSRC}/Config
.if defined(WITH_SESSIONCACHE)
	@${REINPLACE_CMD} "s|^#DB_INCLUDE=.*|DB_INCLUDE=-I${BDB_INCLUDE_DIR}|" ${WRKSRC}/Config
	@${REINPLACE_CMD} "s|^#DB_LIBS=.*|DB_LIBS=-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}|" ${WRKSRC}/Config
.else
	@${REINPLACE_CMD} "s#^SESSION_CACHE_ENABLE = true#SESSION_CACHE_ENABLE = false#" ${WRKSRC}/Config
.endif
	@${REINPLACE_CMD} "s#^RW_USER    = prayer#RW_USER    = _prayer#" ${WRKSRC}/Config

.if defined(WITHOUT_SSL)
	@${REINPLACE_CMD} "s#^SSL_ENABLE           = true#SSL_ENABLE           = false#" ${WRKSRC}/Config
.else
	@${REINPLACE_CMD} "s#CCLIENT_SSL_ENABLE   = false#CCLIENT_SSL_ENABLE   = true#" ${WRKSRC}/Config
.endif

.if defined(WITHOUT_LDAP)
	@${REINPLACE_CMD} "s#LDAP_ENABLE          = true#LDAP_ENABLE          = false#" ${WRKSRC}/Config
.endif

.if defined(WITHOUT_TIDY)
	@${REINPLACE_CMD} "s#TIDY_ENABLE          = true#TIDY_ENABLE          = false#" ${WRKSRC}/Config
.else
	@${REINPLACE_CMD} "s#TIDY_INCLUDE=-I/usr/include/tidy#TIDY_INCLUDE=-I${LOCALBASE}/include/tidy#" ${WRKSRC}/Config
.endif

pre-install:
	@${MKDIR} ${PREFIX}/etc/prayer

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
