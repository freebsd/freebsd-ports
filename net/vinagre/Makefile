# New ports collection makefile for:	vinagre
# Date created:				16 December 2007
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vinagre
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LIB_DEPENDS=	gtk-vnc-1.0.0:${PORTSDIR}/net/gtk-vnc \
    		avahi-core.5:${PORTSDIR}/net/avahi \
		avahi-ui.0:${PORTSDIR}/net/avahi-gtk

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libglade2 gconf2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-avahi
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@-update-desktop-database
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog INSTALL MAINTAINERS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
