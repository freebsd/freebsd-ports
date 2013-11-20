# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/multimedia/libgnome-media-profiles/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	libgnome-media-profiles
PORTVERSION=	3.0.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library that contains code to manage media profiles

CONFLICTS=	gnome-media-2.[0-9]*

NO_STAGE=	yes
USE_GNOME=	gtk30 gconf2 intlhack gnomedocutils
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USES=		gettext gmake pathfix pkgconfig

GCONF_SCHEMAS=	gnome-media-profiles.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|gladeui-3.0|gladeui-5.0|g' ${WRKSRC}/configure

.include <bsd.port.mk>
