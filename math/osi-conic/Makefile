PORTNAME=	osi-conic
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Conic problem solver interface extending OSI to conic problems
WWW=		https://github.com/aykutbulut/OSI-CONIC

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libCoinUtils.so:math/coinutils \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	aykutbulut
GH_PROJECT=	OSI-CONIC

GNU_CONFIGURE=	yes

MAKE_ARGS=	FREEBSD_STAGEDIR=${STAGEDIR}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
