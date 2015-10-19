# Created by: Jonathan Chen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	sigil
PORTVERSION=	0.8.6
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG ePub editor

LICENSE=	GPLv3 # or any later version

BUILD_DEPENDS=	${LOCALBASE}/include/utf8.h:${PORTSDIR}/devel/utf8cpp
LIB_DEPENDS=	libminizip.so:${PORTSDIR}/archivers/minizip \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libpcre16.so:${PORTSDIR}/devel/pcre \
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3

USE_GITHUB=	yes
GH_ACCOUNT=	user-none
GH_PROJECT=	Sigil

USES=		cmake compiler:c++11-lib desktop-file-utils dos2unix \
		ninja pkgconfig python:run shebangfix
USE_QT5=	qmake_build buildtools_build linguisttools_build \
		concurrent gui network printsupport svg webkit \
		widgets xml xmlpatterns
EXCLUDE=	BoostParts Xerces hunspell minizip pcre utf8-cpp zlib
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude src/,}
DOS2UNIX_FILES=	src/FlightCrew/CMakeLists.txt
SHEBANG_FILES=	src/Sigil/Resource_Files/plugin_launchers/python/*.py

OPTIONS_DEFINE=	DEBUG
DEBUG_CFLAGS_OFF=	-DNDEBUG # tidyLib

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|../utf8-cpp|${LOCALBASE}/include|' \
		${WRKSRC}/src/FlightCrew/CMakeLists.txt
# Gentoo: sigil tries to copy non-needed qt libs for deb package, safe
# to ignore this completely
	@${REINPLACE_CMD} -e '/set( QT_LIBS/d' \
		${WRKSRC}/src/Sigil/CMakeLists.txt
.if ${CHOSEN_COMPILER_TYPE} == gcc
# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
	@${REINPLACE_CMD} -i .gch.bak \
		-e '/precompiled_header/d' \
		-e '/add_depend.*PCH/d' \
		${WRKSRC}/src/FlightCrew/CMakeLists.txt
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/${PORTNAME}-real

.include <bsd.port.post.mk>
