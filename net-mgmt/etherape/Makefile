# Created by: Holger Lamm <holger@eit.uni-kl.de>
# $FreeBSD$

PORTNAME=	etherape
PORTVERSION=	0.9.13
CATEGORIES=	net-mgmt gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical network traffic visualization tool for gnome

LICENSE=	GPLv2

USES=		gettext gmake iconv pathfix pkgconfig
USE_GNOME=	gnomedocutils gnomehier libglade2 libgnomeui 
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
