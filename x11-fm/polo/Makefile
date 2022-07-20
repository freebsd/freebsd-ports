PORTNAME=	polo
DISTVERSION=	18.8-beta
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fm

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Advanced graphical file manager written in Vala

LICENSE=	GPLv2+

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib

USES=		desktop-file-utils gettext-tools gmake gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 libxml2 vte3
USE_GITHUB=	yes
GH_ACCOUNT=	teejee2008

WRKSRC_SUBDIR=	src
MAKEFILE=	makefile

post-patch:
	@${RM} ${WRKSRC}/share/polo/files/gtk-theme/*.orig
	@${RM} ${WRKSRC}/share/polo/files/install-*.sh
	@${RM} -r ${WRKSRC}/share/polo/files/udisks2

.include <bsd.port.mk>
