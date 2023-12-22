PORTNAME=	hsl
DISTVERSIONPREFIX=	releases/
DISTVERSION=	2.2.3
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	COIN-OR autotools harness to build HSL linear solvers
WWW=		https://github.com/coin-or-tools/ThirdParty-HSL

LICENSE=	EPL

USES=		fortran gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or-tools
GH_PROJECT=	ThirdParty-HSL

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/coin-or/hsl/CoinHslConfig.h \
		lib/libcoinhsl.so \
		lib/libcoinhsl.so.2 \
		lib/libcoinhsl.so.2.2.3 \
		libdata/pkgconfig/coinhsl.pc

.include <bsd.port.mk>
