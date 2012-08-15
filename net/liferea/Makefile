# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	1.8.7
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/Liferea%20Stable/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2 \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		json-glib-1.0.0:${PORTSDIR}/devel/json-glib

USE_GNOME=	gnomeprefix gnomehack gconf2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-libnotify
MAKE_JOBS_SAFE=	yes

MAN1=		liferea.1
MANLANG=	"" pl
GCONF_SCHEMAS=	liferea.schemas
INSTALLS_ICONS=	yes

LICENSE=	GPLv2

.include <bsd.port.mk>
