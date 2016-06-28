# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssh2
PORTVERSION=	0.12
CATEGORIES=	security pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension to the libssh2 library

LICENSE=	PHP301

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-ssh2

post-patch:
	@${REINPLACE_CMD} -e 's|\$$SSH2_DIR/lib|\$$SSH2_DIR/\$$PHP_LIBDIR|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
