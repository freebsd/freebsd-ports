# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	9.50
CATEGORIES=	print
MASTER_SITES=	https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs${PORTVERSION:S/.//}/
PKGNAMESUFFIX=	9-agpl-x11

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	PostScript and PDF interpreter, X11 support

LICENSE=	AGPLv3

BUILD_DEPENDS=	ghostscript9-agpl-base>=${PORTVERSION}:print/ghostscript9-agpl-base
RUN_DEPENDS=	ghostscript9-agpl-base>=${PORTVERSION}:print/ghostscript9-agpl-base

USES=		cpe gmake iconv localbase pkgconfig tar:xz xorg
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xt

CONFLICTS_INSTALL= \
		ghostscript[789]-[0-9]* \
		ghostscript[789]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*
DISTINFO_FILE=	${.CURDIR:H}/ghostscript9-agpl-base/distinfo
PATCHDIR=	${.CURDIR:H}/ghostscript9-agpl-base/files
CPE_VENDOR=	artifex
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-compile-inits \
		--disable-cups \
		--disable-dbus \
		--disable-gtk \
		--disable-openjpeg \
		--enable-contrib \
		--enable-dynamic \
		--enable-fontconfig \
		--enable-freetype \
		--with-drivers=ALL \
		--with-fontpath=${LOCALBASE}/share/fonts \
		--with-jbig2dec \
		--with-libiconv=maybe \
		--with-libidn \
		--with-libpaper \
		--with-system-libtiff \
		--with-x \
		--without-ijs
ALL_TARGET=	./obj/X11.so
INSTALL_TARGET=	install-shared
PLIST_FILES=	lib/${PORTNAME}/${PORTVERSION}/X11.so

post-patch:
	@${RM} -r ${WRKSRC}/freetype ${WRKSRC}/ijs ${WRKSRC}/jbig2dec \
		${WRKSRC}/jpeg ${WRKSRC}/libpng ${WRKSRC}/openjpeg \
		${WRKSRC}/zlib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTVERSION}/X11.so

.include <bsd.port.mk>
