# $FreeBSD$

PORTNAME=	skylighting-core
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Syntax highlighting library with support for over one hundred languages

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson ansi-terminal attoparsec base64-bytestring blaze-html case-insensitive colour hxt mtl \
		pretty-show regex-pcre regex-pcre-builtin safe utf8-string

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
