PORTNAME=	nuspell
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Free and open source C++ spell checking library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libicuuc.so:devel/icu
TEST_DEPENDS=	catch>0:devel/catch \
		bash:shells/bash

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes
CMAKE_OFF+=	${CMAKE_TESTING_ON}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch:
# Skip README as it only contains install instructions
	@${REINPLACE_CMD} -i .doc '/README/d' ${WRKSRC}/CMakeLists.txt
# Respect PREFIX != /usr/local
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/nuspell/finder.cxx

makepatch-clean:
	@${RM} ${WRKSRC}/tests/suggestiontest/Makefile.orig

.include <bsd.port.mk>

# XXX Don't override definition in Mk/bsd.port.mk
makepatch:	makepatch-clean
