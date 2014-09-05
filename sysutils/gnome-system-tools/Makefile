# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-tools/Makefile,v 1.103 2010/10/25 09:44:29 kwm Exp $

PORTNAME=	gnome-system-tools
PORTVERSION=	2.32.0
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

LIB_DEPENDS=	liboobs-1.so:${PORTSDIR}/devel/liboobs \
		libpolkit-gtk-1.so:${PORTSDIR}/sysutils/polkit-gnome

INSTALLS_ICONS=	yes
USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix intlhack nautilus2
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-services
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.system-tools.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|gmodule-export-2.0|gmodule-export-2.0 gthread-2.0|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^time_admin_LDADD =/s/$$/ -lm/' ${WRKSRC}/src/time/Makefile.in

.include <bsd.port.mk>
