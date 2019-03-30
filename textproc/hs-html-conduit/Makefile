# $FreeBSD$

PORTNAME=	html-conduit
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parse HTML documents using xml-conduit datatypes

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	conduit>=1.0 conduit-extra>=1.1.1 resourcet>=0.3 \
		tagstream-conduit>=0.5.5.3 xml-conduit>=1.3 xml-types>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
