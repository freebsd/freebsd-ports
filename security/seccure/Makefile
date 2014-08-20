# Created by: Lukasz Komsta
# $FreeBSD$

PORTNAME=	seccure
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://point-at-infinity.org/seccure/ \
		${MASTER_SITE_NETBSD}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Elliptic Curve Crypto Utility for Reliable Encryption

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

USE_GCC=	any

.include <bsd.port.mk>
