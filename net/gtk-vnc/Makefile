PORTNAME=	gtk-vnc
PORTVERSION=	1.5.0
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK
WWW=		https://gitlab.gnome.org/GNOME/gtk-vnc

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libsasl2.so:security/cyrus-sasl2

USES=		gettext gnome localbase meson perl5 pkgconfig python \
		tar:xz vala:build xorg
USE_GNOME=	cairo gdkpixbuf gtk30 introspection:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS PULSEAUDIO
OPTIONS_DEFAULT=PULSEAUDIO
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_ENABLED=	gi-docs

PULSEAUDIO_DESC=	use PulseAudio for audio playback
PULSEAUDIO_MESON_ENABLED=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_SUB+=	DOCSDIR2=share/doc/gvnc

.include <bsd.port.mk>
