PORTNAME=	lexilla
DISTVERSION=	5.3.2
CATEGORIES=	textproc
MASTER_SITES=	https://www.scintilla.org/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Free library of language lexers
WWW=		https://www.scintilla.org/Lexilla.html

LICENSE=	SCINTILLA
LICENSE_NAME=	License for Lexilla, Scintilla and SciTE
LICENSE_FILE=	${WRKSRC}/../License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

#LIB_DEPENDS=	libscintilla.so:x11-toolkits/scintilla
BUILD_DEPENDS=	scintilla>0:x11-toolkits/scintilla

USES=		compiler:c++17-lang cpe gmake gnome iconv pkgconfig tar:tgz

USE_LDCONFIG=	yes

MAKEFILE=	makefile
.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=1
.endif
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

CFLAGS+=	-DPIC -fpic

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}/src

PLIST_FILES=	include/lexilla/Lexilla.h \
		include/lexilla/SciLexer.h \
		lib/liblexilla.so

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
MAKE_ARGS+=	CLANG=1
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/lexilla
	${INSTALL_DATA} ${WRKSRC}/../include/*.h \
		${STAGEDIR}${PREFIX}/include/lexilla
	${INSTALL_LIB} ${WRKSRC}/../bin/*.so \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
