# New ports collection makefile for: hs-hscolour
# Date created:        February 22 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hscolour
PORTVERSION=	1.20.2
PORTEPOCH=	1
CATEGORIES=	print haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Colourise Haskell code

LICENSE=	GPLv2
FILE_LICENSE=	LICENCE-GPL

CABAL_SETUP=	Setup.hs

EXECUTABLE=	HsColour

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>

pre-everything::
.if ${PORT_OPTIONS:MHSCOLOUR}
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG} " Please note that you will not be able to build HsColour-enabled "
	@${ECHO_MSG} " documentation without installing HsColour without that first.   "
	@${ECHO_MSG} "================================================================="
	@sleep 5
.endif
