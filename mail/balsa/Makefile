PORTNAME=	balsa
PORTVERSION=	2.6.4
CATEGORIES=	mail gnome
MASTER_SITES=	http://pawsa.fedorapeople.org/balsa/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail reader for the GNOME desktop
WWW=		https://pawsa.fedorapeople.org/balsa/

LICENSE=	GPLv2

BUILD_DEPENDS=	gnome-keyring:security/gnome-keyring \
		itstool:textproc/itstool \
		yelp-tools>=0:textproc/yelp-tools
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libesmtp.so:mail/libesmtp \
		libgmime-3.0.so:mail/gmime30 \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libical.so:devel/libical \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgnutls.so:security/gnutls \
		libfribidi.so:converters/fribidi \
		libsoup-2.4.so:devel/libsoup  \
		libgpgme.so:security/gpgme \
		libcanberra.so:audio/libcanberra \
		libharfbuzz.so:print/harfbuzz \
		libsecret-1.so:security/libsecret \
		libenchant-2.so:textproc/enchant2
RUN_DEPENDS=	gnome-keyring:security/gnome-keyring

USES=		cpe desktop-file-utils gettext gmake gnome iconv libtool pathfix perl5 \
		pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix intlhack libxslt gtksourceview4
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-canberra \
				--with-gtksourceview
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=	LDAP GTKSPELL GTKSV NOTIFY GPG
OPTIONS_DEFAULT=LDAP GTKSPELL GTKSV NOTIFY
OPTIONS_SUB=	yes
GPG_DESC=	GnuPG support
GTKSPELL_DESC=	Spell checking support
GTKSV_DESC=	GtkSourceview support
GPG_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPG_CONFIGURE_WITH=	gpgme
GTKSPELL_LIB_DEPENDS=		libgtkspell3-3.so:textproc/gtkspell3
GTKSPELL_CONFIGURE_WITH=	gtkspell
GTKSV_USE=		GNOME=gtksourceview3
GTKSV_CONFIGURE_WITH=	gtksourceview
LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldap
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_WITH=	libnotify

.include <bsd.port.mk>
