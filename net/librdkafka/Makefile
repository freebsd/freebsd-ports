# Created by: Victor Yagofarov <xnasx@yandex.ru>
# $FreeBSD$

PORTNAME=	librdkafka
PORTVERSION=	0.11.6
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Apache Kafka C/C++ library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to build: undefined reference to __sync_add_and_fetch_4
BROKEN_mips64=		fails to build: undefined reference to __sync_add_and_fetch_4

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		compiler:c11 gmake ssl
USE_GITHUB=	yes

GH_ACCOUNT=	edenhill

GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS+=	--disable-sasl --enable-ssl

USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e \
	's|_ALIGN(|_RE_ALIGN(|g' ${WRKSRC}/src/rdkafka_buf.h \
		${WRKSRC}/src/rdkafka_metadata_cache.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

.include <bsd.port.mk>
