PORTNAME=	syfco
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1-34
DISTVERSIONSUFFIX=	-g0f0f6a6
CATEGORIES=	math lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Synthesis Format Conversion Tool
WWW=		https://github.com/reactive-systems/syfco

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.4.8:lang/ghc94

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	reactive-systems

USE_CABAL=	convertible-1.1.1.1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2
CABAL_FLAGS=	-relocatable

CABAL_EXECUTABLES=	syfco
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

.include <bsd.port.mk>
