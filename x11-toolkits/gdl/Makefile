# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gdl/Makefile,v 1.40 2010/09/29 08:07:46 kwm Exp $

PORTNAME=	gdl
PORTVERSION=	2.30.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
