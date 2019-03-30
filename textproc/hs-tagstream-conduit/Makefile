# $FreeBSD$

PORTNAME=	tagstream-conduit
PORTVERSION=	0.5.5.3
PORTREVISION=	5
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Streamlined HTML tag parser

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	attoparsec>=0.10 blaze-builder case-insensitive conduit>=1.2 \
		conduit-extra>=1.1.0 data-default>=0.5.0 resourcet \
		xml-conduit>=1.1.0.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
