PORTNAME=	libuecc
PORTVERSION=	7
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://git.universe-factory.net/libuecc/snapshot/ \
		http://git.universe-factory.net/libuecc/snapshot/

MAINTAINER=	crest_maintainer@rlwinm.de
COMMENT=	Very small Elliptic Curve Cryptography library
WWW=		https://git.universe-factory.net/libuecc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BROKEN=		Unfetchable
DEPRECATED=	Deprecated, only user was some never properly ported FreiFunk control plane software
EXPIRATION_DATE=2025-04-30

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cmake pkgconfig tar
USE_LDCONFIG=	yes

.include <bsd.port.mk>
