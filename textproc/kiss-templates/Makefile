# Created by: Andreas Sommer <andreas.sommer87@googlemail.com>
# $FreeBSD$

PORTNAME=		kiss-templates
PORTVERSION=		0.19
PORTREVISION=		4
CATEGORIES=		textproc

MAINTAINER=		andreas.sommer87@googlemail.com
COMMENT=		Type safe "Keep it simple, stupid" text templates for C++

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: No known features for CXX compiler GNU

USE_GITHUB=		yes
GH_ACCOUNT=		rbock

PLIST_FILES=		bin/kiste2cpp \
			include/kiste/cpp.h \
			include/kiste/html.h \
			include/kiste/kiste.h \
			include/kiste/raw.h \
			include/kiste/raw_type.h \
			include/kiste/serializer_builder.h \
			include/kiste/terminal.h

USES=			cmake

OPTIONS_DEFINE=		TEST
TEST_DESC=		Build with unit tests
TEST_BUILD_DEPENDS=	boost-libs>=1.55:devel/boost-libs
TEST_USES=		python:2.7,build,test shebangfix
TEST_TEST_TARGET=	test
SHEBANG_FILES=		tests/comparison-based/generate.py tests/differ.py

.include <bsd.port.mk>
