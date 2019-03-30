# $FreeBSD$

PORTNAME=	xml-conduit
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Pure-Haskell utilities for dealing with XML with the conduit package

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	attoparsec>=0.10 blaze-builder>=0.2 blaze-html>=0.5 \
		blaze-markup>=0.5 conduit>=1.0 conduit-extra>=1.1 \
		data-default monad-control>=0.3 resourcet>=0.3 \
		xml-types>=0.3.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
