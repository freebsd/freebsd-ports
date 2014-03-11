# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/netspeed_applet/Makefile,v 1.2 2007/05/19 21:36:17 marcus Exp $

PORTNAME=	netspeed_applet
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	http://launchpadlibrarian.net/49741506/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applet that shows how much network traffic occurs on an interface

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop

INSTALLS_OMF=	yes
USE_GNOME=	gnomehier intlhack gnomeprefix gnomehack gnomepanel
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
