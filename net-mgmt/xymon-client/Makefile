PORTNAME=	xymon
PORTVERSION=	4.3.31
PORTREVISION=	0
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	-client

MAINTAINER=	feld@FreeBSD.org
COMMENT=	System for monitoring servers and networks - Client
WWW=		https://github.com/xymon-monitoring/xymon

LICENSE=	GPLv2

USES=		cpe gmake

USERS=	xymon
GROUPS=	xymon

# Options
XYMONUSER?=	xymon
XYMONHOSTIP?=	127.0.0.1

SUB_LIST+=	XYMONUSER="${XYMONUSER}"

MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV=	MAKE=${MAKE_CMD} XYMONTOPDIR=${WWWDIR}/client MANROOT=${PREFIX}/share/man
MAKE_ENV+=	XYMONUSER="${XYMONUSER}"
MAKE_ENV+=	XYMONHOSTIP="${XYMONHOSTIP}"
MAKE_ENV+=	INSTALLROOT="${STAGEDIR}"
MAKE_ENV+=	PKGBUILD=1
MAKE_ENV+=	MANPREFIX="${STAGEDIR}${PREFIX}/share"
USE_RC_SUBR=	xymon-client
PLIST_SUB+=	XYMONUSER="${XYMONUSER}"
CONFIG_FILES=	clientlaunch.cfg xymonclient.cfg localclient.cfg

USE_GITHUB=	yes
GH_ACCOUNT=	xymon-monitoring
GH_PROJECT=	xymon
GH_TAGNAME=	rel-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--client

post-install:
	${INSTALL_DATA} ${WRKSRC}/client/clientlaunch.cfg ${STAGEDIR}${WWWDIR}/client/etc/clientlaunch.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/client/localclient.cfg ${STAGEDIR}${WWWDIR}/client/etc/localclient.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/client/xymonclient.cfg ${STAGEDIR}${WWWDIR}/client/etc/xymonclient.cfg.sample

.include <bsd.port.mk>
