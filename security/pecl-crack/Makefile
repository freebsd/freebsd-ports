# Created by: Bill Moran <wmoran@collaborativefusion.com>
# $FreeBSD$

PORTNAME=	crack
PORTVERSION=	0.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PECL extension to cracklib

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP30

LIB_DEPENDS=	libcrack.so:security/cracklib

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

EXTRACT_AFTER_ARGS=--no-same-permissions --no-same-owner --exclude libcrack
CONFIGURE_ARGS=	--with-crack=${LOCALBASE}
CFLAGS+=	-Wno-deprecated

post-configure:
	@${REINPLACE_CMD} -e 's|^\$$ini_overwrites.*|&'"'"'crack.default_dictionary=\"${LOCALBASE}/libdata/cracklib/cracklib-words\"'"'"',|' \
		${WRKSRC}/run-tests.php

do-test:
	${MAKE_CMD} -C ${WRKSRC} test < /dev/null

.include <bsd.port.mk>
