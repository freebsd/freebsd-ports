PORTNAME=	bcps
DISTVERSIONPREFIX=	releases/
DISTVERSION=	0.99.2
PORTREVISION=	3
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Branch, Constrain, and Price Software (BiCePS)
WWW=		https://github.com/coin-or/CHiPPS-BiCePS

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Bcps/LICENSE

LIB_DEPENDS=	libAlps.so:math/alps \
		libCoinUtils.so:math/coinutils \
		libopenblas.so:math/openblas

USES=		gmake libtool pkgconfig
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CHiPPS-BiCePS

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
