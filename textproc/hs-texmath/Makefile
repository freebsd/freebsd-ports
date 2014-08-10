# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	texmath
PORTVERSION=	0.6.7
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion of LaTeX math formulas to MathML or OMML

LICENSE=	GPLv2

USE_CABAL=	mtl pandoc-types>=1.12.3.3 parsec>=3 syb xml

FLAGS_DEFINE=		CGI

CGI_DESC=		Compile CGI executable
CGI_FLAG_ENABLE=	cgi
CGI_FLAG_CABAL=		cgi json utf8-string
CGI_FLAG_EXECUTABLE=	texmath-cgi

FLAGS_DISABLE=	test

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
