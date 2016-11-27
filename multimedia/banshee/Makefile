# $FreeBSD$

PORTNAME=	banshee
PORTVERSION=	2.6.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Music management and playback for gnome

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

# Could do without bash, but it's brought in by gnome anyway.
BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgstbase-0.10.so:multimedia/gstreamer \
		libgstfft-0.10.so:multimedia/gstreamer-plugins \
		libwebkitgtk-1.0.so:www/webkit-gtk2 \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	bash:shells/bash

LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:devel/dbus-sharp-glib \
		${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:audio/taglib-sharp \
		${LOCALBASE}/libdata/pkgconfig/mono-zeroconf.pc:net/mono-zeroconf \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/notify-sharp.pc:devel/notify-sharp

OPTIONS_DEFINE=	APPLEDEV DOCS BPMDETECT GIO MTP WEBKIT YOUTUBE
OPTIONS_DEFAULT=APPLEDEV BPMDETECT GIO MTP WEBKIT YOUTUBE
OPTIONS_SUB=	yes

APPLEDEV_DESC=	Apple device
BPMDETECT_DESC=	Force dependency on soundtouch (required for BPM detection)
GIO_DESC=	Use GIO for disk access
WEBKIT_DESC=	Build and/or install extensions using Webkit
YOUTUBE_DESC=	Build and/or install the Youtube extension

USES=		desktop-file-utils gmake gettext-runtime libtool mono pathfix perl5 \
		pkgconfig shared-mime-info sqlite tar:xz
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gnomedocutils gnomesharp20 gtksharp20 intltool
USE_GSTREAMER=	cdparanoia
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME:C/-.*//}
USE_XORG=	x11 xrandr xxf86vm
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-vendor-build-id=FreeBSD\ BSD\#\ Project --disable-gio-hardware --disable-boo
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
PORTSCOUT=	skipv=2.9.1

# Need absolute path for build/icon-install-theme.
INSTALL=	/usr/bin/install

APPLEDEV_CONFIGURE_ENABLE=	appledevice
APPLEDEV_VARS=		LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/libgpod-sharp.pc:audio/libgpod-sharp
BPMDETECT_USE=		gstreamer=soundtouch
DOCS_CONFIGURE_ENABLE=	docs
GIO_CONFIGURE_ENABLE=	gio
GIO_VARS=		LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/gtk-sharp-beans-2.0.pc:x11-toolkits/gtk-sharp-beans
MTP_CONFIGURE_ENABLE=	mtp
MTP_VARS=		LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/libmtp.pc:multimedia/libmtp
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
WEBKIT_CONFIGURE_ENABLE=webkit
WEBKIT_VARS=		LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/webkit-sharp-1.0.pc:www/webkit-sharp
YOUTUBE_CONFIGURE_ENABLE=	youtube
YOUTUBE_VARS=		LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/gdata-sharp-youtube.pc:devel/google-gdata

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBKIT} || ${PORT_OPTIONS:MYOUTUBE}
PLIST_SUB+=	OPT_WEBKITORYOUTUBE=""
.else
PLIST_SUB+=	OPT_WEBKITORYOUTUBE="@comment "
.endif

post-patch:
	${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e 's|-r:Mono.Cairo|-r:${PREFIX}/lib/mono/gac/Mono.Cairo/4.0.0.0__0738eb9f132ed756/Mono.Cairo.dll|'

.include <bsd.port.mk>
