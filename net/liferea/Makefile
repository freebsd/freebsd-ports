# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	liferea

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

.ifdef WITH_MOZILLA
BUILD_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla
.endif

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgtkhtml
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		liferea.1
GCONF_SCHEMAS=	liferea.schemas

.ifdef WITH_MOZILLA
PLIST_SUB=	MOZ=""
.else
PLIST_SUB=	MOZ="@comment "
.endif

post-patch:
.ifdef WITH_MOZILLA
	${REINPLACE_CMD} -e 's,/usr/lib/moz,${X11BASE}/lib/moz,g' \
		${WRKSRC}/src/liferea
.else
	${REINPLACE_CMD} -e 's,gtkmozembed,donttrythis,g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
