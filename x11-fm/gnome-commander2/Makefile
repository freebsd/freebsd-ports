# Created by: Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
# $FreeBSD$
#   $MCom: ports/trunk/x11-fm/gnome-commander2/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	gnome-commander
PORTVERSION=	1.4.1
PORTEPOCH=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-commander/1.2
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	File manager for Gnome2

LICENSE=	GPLv2

LIB_DEPENDS=	libid3.so:${PORTSDIR}/audio/id3lib \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libunique-3.0.so:${PORTSDIR}/x11-toolkits/libunique3 \
		libiptcdata.so:${PORTSDIR}/graphics/libiptcdata

CONFLICTS=	gnome-commander-[0-9]*

USES=		gmake libtool:keepla pathfix tar:xz
USE_GNOME=	gnomedocutils gnomeprefix intlhack libgnomeui
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_OMF=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e 's|unique-1|unique-3|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
