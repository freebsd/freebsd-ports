# $FreeBSD$

PORTNAME=	nuspell
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	textproc

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Free and open source C++ spell checking library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libboost_locale.so:devel/boost-libs \
		libicuuc.so:devel/icu

USES=		autoreconf compiler:c++14-lang gmake libtool pkgconfig
USE_GITHUB=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	catch>0:devel/catch
TEST_CPPFLAGS=		-isystem${LOCALBASE}/include/catch2
TEST_TEST_TARGET=	check

post-patch:
# Skip README as it only contains install instructions
	@${REINPLACE_CMD} 's/ README//' ${WRKSRC}/Makefile.am
# Don't try to download catch2 during build
	@${REINPLACE_CMD} '/wget/d' ${WRKSRC}/tests/Makefile.am
# Respect PREFIX != /usr/local
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/nuspell/finder.cxx

post-patch-TEST-off:
	@${REINPLACE_CMD} -i .notest 's/ tests//' ${WRKSRC}/Makefile.am

pre-install-TEST-on:	do-test

makepatch-clean:
	@${RM} ${WRKSRC}/tests/suggestiontest/Makefile.orig

.include <bsd.port.mk>

# XXX Don't override definition in Mk/bsd.port.mk
makepatch:	makepatch-clean
