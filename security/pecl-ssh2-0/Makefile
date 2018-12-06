# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssh2
PORTVERSION=	0.13
CATEGORIES=	security pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to the libssh2 library

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-ssh2

PORTSCOUT=	limit:^0.*

post-patch:
	@${REINPLACE_CMD} -e 's|\$$SSH2_DIR/lib|\$$SSH2_DIR/\$$PHP_LIBDIR|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
