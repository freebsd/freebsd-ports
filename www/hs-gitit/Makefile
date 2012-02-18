# New ports collection makefile for: hs-gitit
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gitit
PORTVERSION=	0.8.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Wiki using happstack, git or darcs, and pandoc

LICENSE=	GPLv2

USE_CABAL=	cgi ConfigFile>=1 feed>=0.3.6 filestore>=0.4.0.2 \
		happstack-server>=6.0 happstack-util>=6.0 \
		highlighting-kate>=0.2.7.1 hslogger>=1 HStringTemplate>=0.6 \
		HTTP>=4000.0 json>=0.4 mtl network>=2.1.0.0 pandoc>=1.8.2 \
		pandoc-types>=1.8.2 parsec recaptcha>=0.1 safe SHA>1 text \
		url>=2.1 utf8-string>=0.3 xhtml xml>=1.3.5 xss-sanitize>=0.3 \
		zlib>=0.5

EXECUTABLE=	gitit expireGititCache

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
