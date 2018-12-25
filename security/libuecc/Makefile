# $FreeBSD$

PORTNAME=	libuecc
PORTVERSION=	7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://git.universe-factory.net/libuecc/snapshot/ \
		http://git.universe-factory.net/libuecc/snapshot/

MAINTAINER=	crest_maintainer@rlwinm.de
COMMENT=	Very small Elliptic Curve Cryptography library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libsodium.so:security/libsodium

USE_LDCONFIG=	yes

USES=		cmake pkgconfig tar

.include <bsd.port.mk>
