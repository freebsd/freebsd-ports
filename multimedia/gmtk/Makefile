# $FreeBSD$

PORTNAME=	gmtk
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	multimedia gnome devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for gnome-mplayer and gecko-mediaplayer

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix perl5 pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	x11

CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

OPTIONS_DEFINE=	ALSA DOCS GCONF GIO GTK3 NLS PULSEAUDIO
GIO_DESC=	Use GIO for file I/O

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=	--enable-gconf --enable-gsettings
.else
CONFIGURE_ARGS+=	--disable-gconf --enable-keystore
.endif

.if ${PORT_OPTIONS:MGIO}
CONFIGURE_ARGS+=	--with-gio
.else
CONFIGURE_ARGS+=	--without-gio
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=	--enable-gtk3
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--disable-gtk3
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
CONFIGURE_ARGS+=	--with-pulseaudio
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if empty(PORT_OPTIONS:MDOCS)
post-patch:
	@${REINPLACE_CMD} \
	    -e 's/install-data-am: install-gmtkdocDATA/install-data-am:/' \
	    ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
