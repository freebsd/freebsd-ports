# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssh2
PORTVERSION=	0.13
CATEGORIES=	security pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to the libssh2 library

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=	70 71 72

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		php:pecl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-ssh2

PORTSCOUT=	limit:^0.*

post-patch:
	@${REINPLACE_CMD} -e 's|\$$SSH2_DIR/lib|\$$SSH2_DIR/\$$PHP_LIBDIR|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
