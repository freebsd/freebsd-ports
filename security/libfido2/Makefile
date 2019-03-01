# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfido2
PORTVERSION=	0.4.0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides library functionality for FIDO 2.0

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcbor.so:devel/libcbor \
		libhidapi.so.0:comms/hidapi

USES=		cmake pkgconfig ssl

CFLAGS+=	-D_WITH_GETLINE
LDFLAGS+=	-lcrypto

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/libcrypto/d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/man/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|endian.h|sys/&|' ${WRKSRC}/CMakeLists.txt ${WRKSRC}/openbsd-compat/openbsd-compat.h

.include <bsd.port.mk>
