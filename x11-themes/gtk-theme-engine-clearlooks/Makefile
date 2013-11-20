# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gtk-theme-engine-clearlooks/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	gtk-theme-engine-clearlooks
PORTVERSION=	2.91.5
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
#MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
#DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clearlooks theme engine

LICENSE=	LGPL21

NO_STAGE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk30 intlhack 
USES=		gettext gmake pathfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
