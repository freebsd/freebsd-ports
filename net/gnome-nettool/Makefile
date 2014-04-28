# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/gnome-nettool/Makefile,v 1.58 2010/09/28 09:03:44 kwm Exp $

PORTNAME=	gnome-nettool
PORTVERSION=	2.32.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME utility that provides network information statistics

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop

USE_GNOME=	intlhack gnomeprefix libglade2 gconf2 gnomedocutils
GNOME_DESKTOP_VERSION=2
USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-DHAVE_SOCKADDR_SA_LEN
INSTALL_TARGET=	install-strip

post-install:
	${LN} -sf ${PREFIX}/share/gnome-nettool/pixmaps/gnome-nettool.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/gnome-nettool.png

.include <bsd.port.mk>
