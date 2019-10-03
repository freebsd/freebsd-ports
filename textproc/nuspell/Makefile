# $FreeBSD$

PORTNAME=	nuspell
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	2
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

OPTIONS_DEFINE=	MANPAGES TEST
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	ronn:textproc/rubygem-ronn
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

TEST_BUILD_DEPENDS=	catch>0:devel/catch \
			bash:shells/bash
TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test

post-patch:
# Skip README as it only contains install instructions
	@${REINPLACE_CMD} -i .doc '/README/d' ${WRKSRC}/CMakeLists.txt
# Respect PREFIX != /usr/local
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/nuspell/finder.cxx

pre-install-TEST-on:	do-test

makepatch-clean:
	@${RM} ${WRKSRC}/tests/suggestiontest/Makefile.orig

.include <bsd.port.mk>

# XXX Don't override definition in Mk/bsd.port.mk
makepatch:	makepatch-clean
