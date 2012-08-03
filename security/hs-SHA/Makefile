# New ports collection makefile for: hs-SHA
# Date created:        January 8, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SHA
PORTVERSION=	1.5.0.1
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Implementations of the SHA suite of message digest functions

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

OPTIONS_DEFINE=		EXE

EXE_DESC=		Build a SHA2-384 executable similar to 'md5sum'

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--flags="-Test"

.if ${PORT_OPTIONS:MEXE}
CONFIGURE_ARGS+=	--flags="exe"
EXECUTABLE+=		sha1 sha384
.else
CONFIGURE_ARGS+=	--flags="-exe"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
