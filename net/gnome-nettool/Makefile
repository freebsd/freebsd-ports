# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/gnome-nettool3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-nettool
PORTVERSION=	3.2.0
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME utility that provides network information statistics

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop

USE_XZ=		yes
USE_GNOME=	intlhack gnomeprefix gtk30 gnomedocutils
USES=		gettext gmake pathfix
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-DHAVE_SOCKADDR_SA_LEN

GLIB_SCHEMAS=	org.gnome.gnome-nettool.gschema.xml

.include <bsd.port.mk>
