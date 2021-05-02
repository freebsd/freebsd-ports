PORTNAME=	flopc++
DISTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/pkgsource/FlopC++/
PKGNAMEPREFIX=	coin-or-
DISTNAME=	FlopC++-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for solving Linear Optimization Problems in C++

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libCoinUtils.so:math/coinutils \
		libOsi.so:math/osi

USES=		gmake libtool pkgconfig tar:tgz
USE_LDCONFIG=	yes

USE_GCC=	yes # clang breaks: no matching conversion for functional-style cast from 'const flopc::SUBSETREF' to 'flopc::MP_domain' https://github.com/coin-or/FlopCpp/issues/28

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
