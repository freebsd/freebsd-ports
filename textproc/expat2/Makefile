PORTNAME=	expat
DISTVERSION=	2.7.3
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/libexpat/libexpat/releases/download/R_${DISTVERSION:S|.|_|g}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML 1.0 parser written in C
WWW=		https://github.com/libexpat/libexpat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash

USES=		cpe libtool pathfix python:test tar:xz
CPE_VENDOR=	libexpat_project
CPE_PRODUCT=	libexpat
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	EXPAT_VERSION=${DISTVERSION}

CONFIGURE_ARGS=	--without-docbook \
		--without-examples

OPTIONS_DEFINE=	DOCS STATIC TEST
OPTIONS_SUB=	yes

STATIC_CONFIGURE_ENABLE=	static

TEST_USES=	compiler:c++11-lang shebangfix
SHEBANG_FILES=	test-driver-wrapper.sh tests/udiffer.py tests/xmltest.sh
TEST_CONFIGURE_WITH=	tests

.include <bsd.port.mk>
