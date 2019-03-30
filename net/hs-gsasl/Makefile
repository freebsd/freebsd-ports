# $FreeBSD$

PORTNAME=	gsasl
PORTVERSION=	0.3.6
PORTREVISION=	5
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings for GNU libgsasl

LICENSE=	GPLv3

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USES=		pkgconfig
LIB_DEPENDS=	libgsasl.so:security/gsasl

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
