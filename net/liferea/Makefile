# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liferea
PORTVERSION=	1.8.7
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/Liferea%20Stable/${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LICENSE=	GPLv2

LIB_DEPENDS=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2 \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		json-glib-1.0:${PORTSDIR}/devel/json-glib

USES=		gmake pathfix
USE_GNOME=	gnomeprefix gconf2
USE_AUTOTOOLS=	libtool
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-libnotify
MAKE_JOBS_SAFE=	yes

MAN1=		liferea.1
MANLANG=	"" pl
GCONF_SCHEMAS=	liferea.schemas
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
