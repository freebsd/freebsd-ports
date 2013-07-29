# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-tools/Makefile,v 1.103 2010/10/25 09:44:29 kwm Exp $

PORTNAME=	gnome-system-tools
PORTVERSION=	2.32.0
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

LIB_DEPENDS=	oobs-1:${PORTSDIR}/devel/liboobs \
		polkit-gtk-1:${PORTSDIR}/sysutils/polkit-gnome

USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix intlhack nautilus2
USE_AUTOTOOLS=	libtool
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-services
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.system-tools.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|gmodule-export-2.0|gmodule-export-2.0 gthread-2.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
