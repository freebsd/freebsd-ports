PORTNAME=	nuspell
PORTVERSION=	5.1.7
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and safe spellchecking C++ library
WWW=		https://nuspell.github.io/ \
		https://github.com/nuspell/nuspell

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libicuuc.so:devel/icu
TEST_DEPENDS=	catch2>=3.1.1:devel/catch2

USES=		cmake:testing compiler:c++17-lang

CMAKE_OFF=	BUILD_API_DOCS \
		BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS \
		BUILD_TOOLS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes

OPTIONS_DEFINE=	MANPAGES
OPTIONS_EXCLUDE_i386=	MANPAGES # https://github.com/haskell-foundation/foundation/issues/565
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_CMAKE_BOOL=	BUILD_MAN

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/nuspell/finder.cxx

.include <bsd.port.mk>
