# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssh2
PORTVERSION=	1.2
CATEGORIES=	security pear

# https://github.com/php/pecl-networking-ssh2/pull/44/
PATCH_SITES=	https://github.com/php/pecl-networking-ssh2/commit/
PATCHFILES=	167a679db79a93c27b7bb367bef9e0d9abdc47d0.patch:-p1 \
		9e6074a4eae3b4ebbe883ba1b93c9eccb9c78d02.patch:-p1 \
		c9647c5d296e8693d0b5672f1c22945ea024ebdc.patch:-p1

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to the libssh2 library

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		php:pecl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-ssh2

post-patch:
	@${REINPLACE_CMD} -e 's|\$$SSH2_DIR/lib|\$$SSH2_DIR/\$$PHP_LIBDIR|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
