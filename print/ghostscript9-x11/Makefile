PORTNAME=	ghostscript
PORTVERSION=	9.06
PORTREVISION=	12
CATEGORIES=	print
MASTER_SITES=	http://downloads.ghostscript.com/public/ \
		SF/ghostscript/GPL%20Ghostscript/${PORTVERSION}/
PKGNAMESUFFIX=	9-x11
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 9.x PostScript interpreter, X11 support

LICENSE=	GPLv3

CONFLICTS_INSTALL= \
		gambc-[0-9]* \
		ghostscript[789]-[0-9]* \
		ghostscript[789]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*

USES=		autoreconf ghostscript:9 gmake tar:bzip2 xorg
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xt
EXTRACT_AFTER_ARGS=	${EXCLUDE_DIRS:S/^/--exclude /}
GNU_CONFIGURE=	yes
MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XLDFLAGS="${XLDFLAGS}"
CONFIGURE_ENV=	${MAKE_ENV}
CONFIGURE_ARGS=	--disable-compile-inits \
		--disable-contrib \
		--enable-dynamic \
		--disable-freetype \
		--without-system-libtiff \
		--without-ijs \
		--without-libidn \
		--without-jasper \
		--without-libpaper \
		--with-x \
		--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--with-drivers=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
XLDFLAGS=	-lpthread
ALL_TARGET=	./obj/X11.so
INSTALL_TARGET=	install-shared
PLIST_FILES=	${GS_LIBDIR}/X11.so

GS_LIBDIR=	lib/${PORTNAME}/${PORTVERSION}
EXCLUDE_DIRS=	freetype jbig2dec jpeg expat jasper lcms lcms2 libpng tiff zlib

pre-build:
	${MKDIR} ${WRKSRC}/obj

.include <bsd.port.mk>
