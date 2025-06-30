PORTNAME=	balsa
PORTVERSION=	2.6.5
PORTREVISION=	3
CATEGORIES=	mail gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail reader for the GNOME desktop
WWW=		https://pawsa.fedorapeople.org/balsa/

LICENSE=	GPLv2

LIB_DEPENDS=	libgmime-3.0.so:mail/gmime30 \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libical.so:devel/libical \
		libgnutls.so:security/gnutls \
		libfribidi.so:converters/fribidi \
		libgpgme.so:security/gpgme \
		libcanberra.so:audio/libcanberra \
		libharfbuzz.so:print/harfbuzz \
		libsoup-3.0.so:devel/libsoup3 \
		libgcr-base-3.so:security/gcr3 \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41 \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	gnome-keyring:security/gnome-keyring

USES=		cpe desktop-file-utils gettext-runtime gettext-tools gnome iconv \
		localbase meson pkgconfig sqlite tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	glib20 gtk30 gtksourceview4 libxml2
MESON_ARGS=	-Dsysconfdir=${LOCALBASE}/etc \
		-Dautocrypt=true \
		-Dcanberra=true \
		-Dhtml-widget=webkit2 \
		-Dgtksourceview=true \
		-Dgpe=true \
		-Dwebdav=true \
		-Dgcr=true

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME

OPTIONS_DEFINE=	SPELL
OPTIONS_DEFAULT=SPELL

SPELL_DESC=	Spell checking support
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell
SPELL_MESON_ON=		-Dspell-checker=gspell
SPELL_LIB_DEPENDS_OFF=	libenchant-2.so:textproc/enchant2
SPELL_MESON_OFF=	-Dspell-checker=internal

.include <bsd.port.mk>
