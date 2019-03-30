# $FreeBSD$

PORTNAME=	network-protocol-xmpp
PORTVERSION=	0.4.8
PORTREVISION=	6
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Client library for the XMPP protocol

LICENSE=	GPLv3

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	gnuidn>=0.2 gnutls>=0.1.4 gsasl>=0.3 libxml-sax>=0.7 \
		monads-tf>=0.1 network>=2.2 xml-types>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
