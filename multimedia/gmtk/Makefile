# $FreeBSD$

PORTNAME=	gmtk
PORTVERSION=	1.0.9
CATEGORIES=	multimedia gnome devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE:S,/files/,/svn/packages/,}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for gnome-mplayer and gecko-mediaplayer

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		gettext gmake libtool pathfix perl5 pkgconfig
USE_XORG=	x11
USE_GNOME=	glib20
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-gconf
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		ALSA DOCS GIO GTK3 PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa
GIO_DESC=		Use GIO for file I/O
GIO_CONFIGURE_WITH=	gio
GTK3_USE=		gnome=gtk30
GTK3_CONFIGURE_ENABLE=	gtk3
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk20
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/COPYING\\/d ; \
		 /INSTALL\\/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
