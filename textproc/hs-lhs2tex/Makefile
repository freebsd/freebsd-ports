PORTNAME=	lhs2tex
PORTVERSION=	1.25
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Preprocessor for typesetting Haskell sources with LaTeX
WWW=		https://www.andres-loeh.de/lhs2tex/

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc-9.8.4:lang/ghc98

USES=		cabal tex
USE_CABAL=	regex-base-0.94.0.2_4 \
		regex-compat-0.95.2.1_2 \
		regex-posix-0.96.0.1_3
USE_TEX=	latex dvipsk

CABAL_EXECUTABLES=	lhs2TeX

BINARY_ALIAS=	ghci=${LOCALBASE}/bin/ghci-9.8.4

.include <bsd.port.mk>
