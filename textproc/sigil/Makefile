# Created by: Jonathan Chen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	sigil
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG ePub editor

LICENSE=	GPLv3+

LIB_DEPENDS=	libminizip.so:archivers/minizip \
		libpcre.so:devel/pcre \
		libhunspell-1.5.so:textproc/hunspell
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py3-lxml

USE_GITHUB=	yes
GH_ACCOUNT=	Sigil-Ebook
GH_PROJECT=	Sigil

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		pkgconfig python:3 shebangfix
SHEBANG_FILES=	src/Resource_Files/plugin_launchers/python/*.py \
		src/Resource_Files/python3lib/*.py
USE_QT5=	concurrent core gui network printsupport svg webkit \
		widgets xml xmlpatterns \
		buildtools_build linguisttools_build qmake_build \
		imageformats_run
CMAKE_ARGS=	-DUSE_SYSTEM_LIBS:BOOL=1 \
		-DINSTALL_BUNDLED_DICTS:BOOL=0
USE_LDCONFIG=	${PREFIX}/lib/sigil

# Upstream uses pkg-config output to pass libhunspell-1.5.so and
# libpcre16.so to the linker. pkg-config output does not include full
# paths, so add a workaround to keep the port linking for now.
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sigil/*.so

.include <bsd.port.mk>
