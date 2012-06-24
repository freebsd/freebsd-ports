# New ports collection makefile for: hs-xml2html
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xml2html
PORTVERSION=	0.1.2.3
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	blaze-html instances for xml-conduit types

LICENSE=	BSD

USE_CABAL=	blaze-html>=0.4 blaze-markup>=0.5.1 text>=0.5 xml-conduit>=0.5

CONFIGURE_ARGS+=	--flags="-blaze_html_0_5"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
