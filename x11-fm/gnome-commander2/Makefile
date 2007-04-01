# New ports collection makefile for:	gnomem-commander
# Date created:		23 April 2002
# Whom:			Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
#
# $FreeBSD$
#

PORTNAME=	gnome-commander
PORTVERSION=	1.2.3
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-commander/1.2
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	araujo@bsdmail.org
COMMENT=	File manager for Gnome2

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		exif.12:${PORTSDIR}/graphics/libexif \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata

BROKEN=		Does not build

CONFLICTS=	gnome-commander-*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomedocutils gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
INSTALLS_OMF=	yes

MAN1=		gnome-commander.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/pixmaps|share/gnome/pixmaps|g' ${WRKSRC}/configure

.include <bsd.port.mk>
