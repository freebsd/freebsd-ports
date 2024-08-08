PORTNAME=	nuspell
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.6
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and safe spellchecking C++ library
WWW=		https://nuspell.github.io/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libicuuc.so:devel/icu
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes
CMAKE_OFF+=	${CMAKE_TESTING_ON}
PLIST_SUB=	VERSION=${PORTVERSION}


OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_EXCLUDE_i386=	MANPAGES # https://github.com/haskell-foundation/foundation/issues/565

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_CMAKE_BOOL=	BUILD_DOCS
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

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
