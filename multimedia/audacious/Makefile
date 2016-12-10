# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious
PORTVERSION=	3.8.1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Lightweight and versatile audio player

LICENSE=	GPLv3

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
	libfreetype.so:print/freetype2 \
	libfontconfig.so:x11-fonts/fontconfig

CONFLICTS_INSTALL=	audacious-gtk3-3.*

SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake \
	localbase pkgconfig tar:bzip2
USE_XORG=	x11 sm
USE_GNOME=	gtk20 glib20 cairo
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
EXECINFO_USES=	execinfo
OPTIONS_SUB=	yes
EXECINFO_DESC=	Build with libexecinfo support

.include <bsd.port.options.mk>

post-patch:
.if  ${PORT_OPTIONS:MEXECINFO} || exists(${LOCALBASE}/lib/libexecinfo.so)
	@${REINPLACE_CMD} 's|-lm |-lm -L${LOCALBASE}/lib -lexecinfo |' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/audacious.pc.in
.endif
	${REINPLACE_CMD} -e 's| $${MFLAGS}||g' \
		${WRKSRC}/buildsys.mk.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aud*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*

.include <bsd.port.mk>
