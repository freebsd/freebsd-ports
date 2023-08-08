PORTNAME=	parfetch
DISTVERSION=	0.1.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://codeberg.org/attachments/44b0e45e-94e6-4852-b9f1-700e104e6238?dummy=/
PKGNAMESUFFIX=	-overlay

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fetch distfiles in parallel and with pipelining
WWW=		https://codeberg.org/tobik/parfetch-overlay

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Unmaintained
EXPIRATION_DATE=	2023-08-31

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		compiler:c11 ninja pkgconfig ssl tar:lz
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	AR="${AR}" \
		CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		DESTDIR="${STAGEDIR}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		LDFLAGS="${LDFLAGS}" \
		PREFIX="${PREFIX}"
SUB_FILES=	pkg-message

.include <bsd.port.mk>
