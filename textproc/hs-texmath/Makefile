# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	texmath
PORTVERSION=	0.6.1.5
PORTREVISION=	3
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion of LaTeX math formulas to MathML or OMML

LICENSE=	GPLv2

USE_CABAL=	parsec>=3 syb xml

OPTIONS_DEFINE=		CGI

CGI_DESC=		Compile CGI executable

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MCGI}
CONFIGURE_ARGS+=	--flags="cgi"
USE_CABAL+=		cgi json utf8-string
EXECUTABLE+=		texmath-cgi
.else
CONFIGURE_ARGS+=	--flags="-cgi"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
