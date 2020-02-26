# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfido2
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides library functionality for FIDO 2.0

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcbor.so:devel/libcbor \
		libhidapi.so.0:comms/hidapi

USES=		cmake compiler pkgconfig ssl

CFLAGS+=	-D_WITH_GETLINE -DUSE_HIDAPI
LDFLAGS+=	-lcrypto -lusbhid

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/libcrypto/d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|endian.h|sys/&|' ${WRKSRC}/CMakeLists.txt ${WRKSRC}/openbsd-compat/openbsd-compat.h
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e '/-Wno-unused-result/d; /-Wno-discarded-qualifiers/d' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
