PORTNAME=	zapret
DISTVERSIONPREFIX=	v
DISTVERSION=	71.3
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DPI (Deep Packet Interderence) bypass (multi platform)
WWW=		https://github.com/bol-van/zapret

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	bol-van

EXES=		dvtws ip2net mdig tpws

PLIST_FILES=	${EXES:S/^/bin\//}

do-install:
.for exe in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/my/${exe} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
