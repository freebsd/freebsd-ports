# Created by: Bill Moran <wmoran@collaborativefusion.com>
# $FreeBSD$

PORTNAME=	crack
PORTVERSION=	0.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PECL extension to cracklib

LICENSE=	PHP30

LIB_DEPENDS=	libcrack.so:security/cracklib

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

EXTRACT_AFTER_ARGS=--no-same-permissions --no-same-owner --exclude libcrack
CONFIGURE_ARGS=	--with-crack=${LOCALBASE}
CFLAGS+=	-Wno-deprecated

post-configure:
	${REINPLACE_CMD} -e 's|^\$$ini_overwrites.*|&'"'"'crack.default_dictionary=\"${LOCALBASE}/libdata/cracklib/pw_dict\"'"'"',|' \
		${WRKSRC}/run-tests.php

test check regression-test: build
	${MAKE} -C ${WRKSRC} test < /dev/null

.include <bsd.port.mk>
