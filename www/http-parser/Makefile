# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	http-parser
PORTVERSION=	2.9.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	HTTP request/response parser written in C

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	nodejs

USES=		gmake
USE_LDCONFIG=	yes
MAKE_ENV=	STRIP="${STRIP}"
ALL_TARGET=	library
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

PLIST_FILES=	include/http_parser.h lib/libhttp_parser.so \
		lib/libhttp_parser.so.${PORTVERSION:R} \
		lib/libhttp_parser.so.${PORTVERSION}

.include <bsd.port.mk>
