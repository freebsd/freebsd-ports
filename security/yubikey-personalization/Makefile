# $FreeBSD$

PORTNAME=	yubikey-personalization
PORTVERSION=	1.17.2
CATEGORIES=	security

MAINTAINER=	romain@FreeBSD.org
COMMENT=	YubiKey personalization library and tool

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libyubikey.so:${PORTSDIR}/security/libyubikey

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico
GH_TAGNAME=	v${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pathfix
USE_LDCONFIG=	yes

.include <bsd.port.mk>
