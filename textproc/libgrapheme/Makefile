PORTNAME=	libgrapheme
DISTVERSION=	3.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://dl.suckless.org/${PORTNAME}/

MAINTAINER=	kfv@FreeBSD.org
COMMENT=	Freestanding C99 library for Unicode string handling
WWW=		https://libs.suckless.org/libgrapheme/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LDCONFIG= \
		LDFLAGS="${LDFLAGS}" \
		PCPREFIX="${PREFIX}/libdata/pkgconfig" \
		PREFIX="${PREFIX}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.${DISTVERSION}

.include <bsd.port.mk>
