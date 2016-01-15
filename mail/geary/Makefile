# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/mail/geary/Makefile 20050 2014-11-10 09:22:41Z gusi $

PORTNAME=	geary
PORTVERSION=	0.10.0
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail client for GNOME 3

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libgcr-3.so:${PORTSDIR}/security/gcr

USES=		cmake desktop-file-utils gettext gmake \
		libtool pkgconfig shebangfix tar:xz
USE_GNOME=	gnomedocutils gnomeprefix gtk30 intlhack
SHEBANG_FILES=	desktop/geary-attach
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.yorba.geary.gschema.xml

post-patch:
		@${REINPLACE_CMD} -e 's|abort $$option||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
