# Created by: Glenn Johnson <gljohns@bellsouth.net>
# $FreeBSD$
#   $MCom$

PORTNAME=	balsa
PORTVERSION=	2.5.1
PORTREVISION=	3
CATEGORIES=	mail gnome
MASTER_SITES=	http://pawsa.fedorapeople.org/balsa/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail reader for the GNOME desktop

BUILD_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		itstool:${PORTSDIR}/textproc/itstool \
		yelp-tools>=0:${PORTSDIR}/textproc/yelp-tools
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libesmtp.so:${PORTSDIR}/mail/libesmtp \
		libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnome-keyring

# Depends on gtkhtml4 (which is being abandonend). When our webkitgtk3 
# in ports gets updated to > 1.10.x, balsa should depend on it.
USES=		desktop-file-utils gettext gmake iconv pathfix \
		perl5 pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gtkhtml4 intlhack libxslt
INSTALLS_ICONS=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads \
		--disable-more-warnings \
		--with-ssl \
		--without-nm \
		--with-html-widget=gtkhtml4 \
		--with-gmime=2.6 \
		--with-canberra
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LDAP GTKSPELL GTKSV NOTIFY GPG
OPTIONS_DEFAULT=LDAP GTKSPELL GTKSV NOTIFY
GTKSPELL_DESC=	Spell checking support
GTKSV_DESC=	GtkSourceview support
GPG_DESC=	GnuPG support
GPG_CONFIGURE_WITH=	gpgme
GPG_LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap
GTKSPELL_CONFIGURE_WITH=	gtkspell
GTKSPELL_LIB_DEPENDS=		libgtkspell3-3.so:${PORTSDIR}/textproc/gtkspell3
GTKSV_USE=		GNOME=gtksourceview3
GTKSV_CONFIGURE_WITH=	gtksourceview
NOTIFY_CONFIGURE_WITH=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

.include <bsd.port.mk>
