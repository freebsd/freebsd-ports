PORTNAME=	flopc++
DISTVERSION=	1.2.5.20200527
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for solving Linear Optimization Problems in C++

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libCoinUtils.so:math/coinutils \
		libOsi.so:math/osi

USES=		gmake libtool pkgconfig tar:tgz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	FlopCpp
GH_TAGNAME=	d4c1d98 # fix-clang branch

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
