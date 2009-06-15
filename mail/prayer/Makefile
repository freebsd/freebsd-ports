# New ports collection makefile for:    prayer
# Date created:         27 Dez 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	prayer
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Prayer Webmail System

BUILD_DEPENDS=	${LOCALBASE}/lib/libc-client4.a:${PORTSDIR}/mail/cclient

USE_OPENLDAP=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_PERL5_BUILD=yes
USE_ICONV=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	PORTCFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		PORTLDFLAGS="${LDFLAGS}"

PORTDOCS=	ACCOUNTD CMD_LINE DESIGN DONE DONE-OLD FEATURES ICONLIST \
		INSTALL LOGS NOTICE README ROADMAP SECURITY TODO

USE_RC_SUBR=	prayer

OPTIONS=	SESSIONCACHE	"Activate Session Cache" On

MAN5=		prayer.cf.5
MAN8=		prayer-session.8 prayer-ssl-prune.8 prayer.8

.include <bsd.port.pre.mk>

.if defined(WITH_SESSIONCACHE)
USE_BDB=	yes
.endif

pre-patch:
	@${CP} ${WRKSRC}/defaults/Config ${WRKSRC}/Config

post-patch:
	# correct chroot
	@${REINPLACE_CMD} "s#\"/chroot/prayer\"#config->var_prefix#" ${WRKSRC}/servers/prayer_chroot.c
	# change the user in the default config
	@${REINPLACE_CMD} "s#prayer_user           = \"prayer\"#prayer_user           = \"_prayer\"#" ${WRKSRC}/files/etc/prayer.cf.SRC
	@${REINPLACE_CMD} "s#%%PREFIX%%#${PREFIX}#" ${WRKSRC}/Config

post-configure:
.if defined(WITH_SESSIONCACHE)
	@${REINPLACE_CMD} "s#^DB_INCLUDE=.*#DB_INCLUDE=-I${BDB_INCLUDE_DIR}#" ${WRKSRC}/Config
	@${REINPLACE_CMD} "s#^DB_LIBS=.*#DB_LIBS=-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}#" ${WRKSRC}/Config
.else
	@${REINPLACE_CMD} "s#^SESSION_CACHE_ENABLE = true#SESSION_CACHE_ENABLE = false#" ${WRKSRC}/Config
.endif
	@${REINPLACE_CMD} "s#^RW_USER    = prayer#RW_USER    = _prayer#" ${WRKSRC}/Config

pre-install:
	@${MKDIR} ${PREFIX}/etc/prayer
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
