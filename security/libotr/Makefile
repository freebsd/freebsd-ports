# $FreeBSD$

PORTNAME=	libotr
PORTVERSION=	4.1.1
CATEGORIES=	security net-im net
MASTER_SITES=	https://otr.cypherpunks.ca/ \
		http://www.c-s.li/ports/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Portable OTR Messaging Library and toolkit

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt

CONFLICTS=	libotr3-*

GNU_CONFIGURE=	yes
USES=		libtool pathfix cpe
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	cypherpunks

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

.include <bsd.port.mk>
