# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-pkgview/Makefile,v 1.6 2007/05/30 03:21:44 mezz Exp $

PORTNAME=	gnome-pkgview
PORTVERSION=	1.0.7
PORTREVISION=	5
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.mikegtn.net/packages/gnome-pkgview/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Displays the version of GNOME components installed

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeui intlhack
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-pkgview.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/config-path.c

.include <bsd.port.mk>
