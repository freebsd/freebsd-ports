# New ports collection makefile for:	gtkhtml3
# Date created:				12 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gtkhtml38/Makefile,v 1.106 2008/01/29 01:43:06 marcus Exp $
#

PORTNAME=	gtkhtml3
PORTVERSION=	3.12.3
PORTREVISION=	3
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight HTML rendering/printing/editing engine

LIB_DEPENDS=	soup-2.2.8:${PORTSDIR}/devel/libsoup22

NO_LATEST_LINK=	yes
DEPRECATED=	Older API; newer applications should use www/gtkhtml3

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gail libgnomeui ltverhack \
		libgnomeprintui
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="3.8"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
	    	's|-DG_DISABLE_DEPRECATED[^[:space:]]+||g'

.include <bsd.port.mk>
