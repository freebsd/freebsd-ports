# New ports collection makefile for: hs-http-server
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	http-server
PORTVERSION=	1
PORTREVISION=	5
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A library for writing Haskell web servers

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	HTTP>=4000.0.7 mime>=0.3 network>=2 url>=2 utf8-string>=0.3.4

INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/example && \
			  ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

.if !defined(NOPORTEXAMPLES)
SUB_FILES=	pkg-message
SHOW_PKGMSG=	yes
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
