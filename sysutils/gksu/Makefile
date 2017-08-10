# Created by: Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
# Modified by: Michael Reim <kraileth@elderlinux.org>
# $FreeBSD$

PORTNAME=			gksu
PORTVERSION=			2.0.2
PORTREVISION=			7
CATEGORIES=			sysutils
MASTER_SITES=			http://people.debian.org/~kov/gksu/

MAINTAINER=			ports@FreeBSD.org
COMMENT=			Graphical frontend to su
LICENSE=        		GPLv2

LIB_DEPENDS=			libgksu2.so:sysutils/libgksu \
				libgnome-keyring.so:security/libgnome-keyring

OPTIONS_DEFINE=                 NAUT_EXT
OPTIONS_DEFAULT=                NAUT_EXT
OPTIONS_SUB=                    yes

NAUT_EXT_DESC=                  Build extension for the Nautilus file manager
NAUT_EXT_LIB_DEPENDS=           libnautilus-extension.so:x11-fm/nautilus
NAUT_EXT_CONFIGURE_ENABLE=      nautilus-extension
NAUT_EXT_PLIST_FILES+=          lib/nautilus/extensions-2.0/libnautilus-gksu.so \
                                lib/nautilus/extensions-2.0/libnautilus-gksu.a

USES=				gettext-tools gmake libtool pathfix pkgconfig
USE_GNOME=			gconf2 gnomeprefix gtk20 intlhack
GNU_CONFIGURE=			yes
USE_LDCONFIG=			yes
CPPFLAGS+=			-I${LOCALBASE}/include
LDFLAGS+=			-L${LOCALBASE}/lib
INSTALL_TARGET=			install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gkeyfile.h|glib.h|g' \
		${WRKSRC}/nautilus-gksu/libnautilus-gksu.c

.include <bsd.port.mk>
