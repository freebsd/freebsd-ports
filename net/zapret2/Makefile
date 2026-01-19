PORTNAME=	zapret2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.6
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DPI (Deep Packet Interderence) bypass (Gen 2)
WWW=		https://github.com/bol-van/zapret

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.txt

USES=		lua luajit pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	bol-van

PLIST_FILES=	${EXES:S/^/bin\//}

EXES=		dvtws2 ip2net mdig

do-install:
.for exe in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/my/${exe} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
