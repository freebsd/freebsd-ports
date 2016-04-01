# $FreeBSD$

PORTNAME=	libotr
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	security net-im net
MASTER_SITES=	http://www.c-s.li/ports/ \
		https://otr.cypherpunks.ca/
PKGNAMESUFFIX=	3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Portable OTR Messaging Library and toolkit

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt

CONFLICTS=	libotr-*

GNU_CONFIGURE=	yes
USES=		cpe libtool pathfix
USE_LDCONFIG=	yes
CPE_VENDOR=	cypherpunks

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

.include <bsd.port.mk>
