PORTNAME=	zapret
DISTVERSIONPREFIX=	v
DISTVERSION=	72.2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DPI (Deep Packet Interderence) bypass (multi platform)
WWW=		https://github.com/bol-van/zapret

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	bol-van

PLIST_FILES=	${EXES:S/^/bin\//}

EXES=		dvtws ip2net mdig tpws

do-install:
.for exe in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/my/${exe} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
