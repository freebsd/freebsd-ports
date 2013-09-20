# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gdl/Makefile,v 1.40 2010/09/29 08:07:46 kwm Exp $

PORTNAME=	gdl
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
