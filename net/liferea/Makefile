# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	1.6.6
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/Liferea%20Stable/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2

USE_GNOME=	gnomeprefix gnomehack libglade2 gconf2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-libnotify
MAKE_JOBS_SAFE=	yes

MAN1=		liferea.1
MANLANG=	"" pl
GCONF_SCHEMAS=	liferea.schemas
INSTALLS_ICONS=	yes

post-patch:
	@${CP} ${FILESDIR}/liferea_dbus.xml ${WRKSRC}/src

.include <bsd.port.mk>
