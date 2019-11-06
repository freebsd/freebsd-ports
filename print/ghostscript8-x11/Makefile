# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	8.71
PORTREVISION=	19
CATEGORIES=	print
MASTER_SITES=	http://downloads.ghostscript.com/public/ \
		SF/ghostscript/GPL%20Ghostscript/${PORTVERSION}/ \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/GPL/gs${PORTVERSION:S/.//}/
PKGNAMESUFFIX=	8-x11
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 8.x PostScript interpreter, X11 support

LICENSE=	GPLv3

CONFLICTS_INSTALL= \
		gambc-[0-9]* \
		ghostscript[789]-[0-9]* \
		ghostscript[789]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*

USES=		autoreconf ghostscript:8 gmake tar:xz xorg
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xt
GNU_CONFIGURE=	yes
EXTRACT_AFTER_ARGS=	${EXCLUDE_DIRS:S/^/--exclude /}
MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XLDFLAGS="${XLDFLAGS}"
CONFIGURE_ENV=	${MAKE_ENV}
CONFIGURE_ARGS=	--disable-compile-inits \
		--disable-contrib \
		--enable-dynamic \
		--without-ijs \
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
EXCLUDE_DIRS=	jbig2dec jpeg expat jasper libpng tiff zlib

pre-build:
	${MKDIR} ${WRKSRC}/obj

.include <bsd.port.mk>
