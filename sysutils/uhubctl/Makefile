PORTNAME=     uhubctl
DISTVERSIONPREFIX= v
DISTVERSION=  2.6.0
CATEGORIES=   sysutils

MAINTAINER=   tomek@cedro.info
COMMENT=      Utility to control USB power per-port on smart USB hubs
WWW=          https://github.com/mvp/uhubctl

LICENSE=      GPLv2
LICENSE_FILE= ${WRKSRC}/LICENSE

USES=         gmake pkgconfig
USE_GITHUB=   yes
GH_ACCOUNT=   mvp

ALL_TARGET=   uhubctl

PLIST_FILES=  sbin/uhubctl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhubctl ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
