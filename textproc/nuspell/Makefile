# $FreeBSD$

PORTNAME=	nuspell
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	textproc

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Free and open source C++ spell checking library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libboost_locale.so:devel/boost-libs \
		libicuuc.so:devel/icu

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS TEST

DOCS_BUILD_DEPENDS=	ronn:textproc/rubygem-ronn

TEST_BUILD_DEPENDS=	catch>0:devel/catch \
			bash:shells/bash
TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test

post-patch:
# Skip README as it only contains install instructions
	@${REINPLACE_CMD} -i .doc '/README/d' ${WRKSRC}/CMakeLists.txt
# Switch to system Catch2 and use IMPORTED target
	@${REINPLACE_CMD} -i .catch '/Catch2/,//d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i .catch -e '/CMAKE_MODULE_PATH/,/Catch2/d' \
		-e $$'/include.*Catch/i\\\nfind_package(Catch2 REQUIRED)\n' \
		-e '/target_link_libraries/s/Catch2/&::&/' \
		${WRKSRC}/tests/CMakeLists.txt
# Respect PREFIX != /usr/local
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/nuspell/finder.cxx

pre-install-TEST-on:	do-test

makepatch-clean:
	@${RM} ${WRKSRC}/tests/suggestiontest/Makefile.orig

.include <bsd.port.mk>

# XXX Don't override definition in Mk/bsd.port.mk
makepatch:	makepatch-clean
