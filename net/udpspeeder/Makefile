PORTNAME=	udpspeeder
DISTVERSION=	20260731
CATEGORIES=	net net-vpn

MAINTAINER=	pouria@FreeBSD.org
COMMENT=	Tunnel which improves a high-latency lossy link by using FEC
WWW=		https://github.com/wangyu-/UDPspeeder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	wangyu-
GH_PROJECT=	UDPspeeder
GH_TAGNAME=	b6a1b5941d9ebb6ef4f6866abdf1e03a47b99b2d

USE_RC_SUBR=	speederv2

# https://github.com/wangyu-/UDPspeeder/pull/353
MAKEFILE=	makefile
# gitversion= replaces the $(shell .)
MAKE_ARGS=	gitversion=${GH_TAGNAME}
# cross_cxx is the only target that honours FLAGS
ALL_TARGET=	cross_cxx

PLIST_FILES=	bin/speederv2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/speederv2_cross ${STAGEDIR}${PREFIX}/bin/speederv2

.include <bsd.port.mk>
