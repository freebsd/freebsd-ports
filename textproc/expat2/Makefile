# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.2.10
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/libexpat/libexpat/releases/download/R_${PORTVERSION:S|.|_|g}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML 1.0 parser written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash

GNU_CONFIGURE=	yes
USES=		libtool pathfix python:test tar:xz
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-docbook --without-examples
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_SUB=	yes

TEST_USES=	shebangfix
SHEBANG_FILES=	test-driver-wrapper.sh tests/udiffer.py tests/xmltest.sh
TEST_CONFIGURE_WITH=	tests
TEST_TARGET=	check

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/xmlwf.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
