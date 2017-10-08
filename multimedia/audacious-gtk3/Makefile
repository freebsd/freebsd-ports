# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious
PORTVERSION=	3.9
DISTVERSIONSUFFIX=	-gtk3
CATEGORIES=	multimedia audio
#MASTER_SITES=	http://distfiles.audacious-media-player.org/
PKGNAMESUFFIX=	${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+3 port of lightweight and versatile audio player

LICENSE=	GPLv3

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
	libfontconfig.so:x11-fonts/fontconfig

CONFLICTS_INSTALL=	audacious-3.*

MASTERDIR=	${.CURDIR}/../audacious
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${MASTERDIR}/files
SUB_FILES=	pkg-message

USES=		autoreconf compiler:c++11-lib desktop-file-utils \
		gettext-tools gmake localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	audacious-media-player
GH_TAGNAME=	7a490de

GNU_CONFIGURE=	yes
USE_XORG=	x11 sm
USE_GNOME=	gtk30 glib20 cairo
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
	--enable-gtk \
	--without-buildstamp

OPTIONS_DEFINE=	ICONV NLS EXECINFO
OPTIONS_DEFAULT=ICONV EXECINFO
ICONV_USES=	iconv
NLS_USES=	gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls
NLS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-Makefile
OPTIONS_SUB=	yes
EXECINFO_DESC=	Build with libexecinfo support

.include <bsd.port.options.mk>

post-patch:
.if  ${PORT_OPTIONS:MEXECINFO}
	@${REINPLACE_CMD} 's|-lm |-lm -lexecinfo |' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -lexecinfo|' \
		${WRKSRC}/audacious.pc.in
.endif
	${REINPLACE_CMD} -e 's| $${MFLAGS}||g' \
		${WRKSRC}/buildsys.mk.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aud*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*

.include <bsd.port.mk>
