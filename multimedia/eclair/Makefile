# New ports collection makefile for:	eclair
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	eclair
PORTVERSION=	20060719
CATEGORIES=	multimedia
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	An EFL powered media player

LIB_DEPENDS=	ecore.1:${PORTSDIR}/x11/ecore \
		edje.5:${PORTSDIR}/graphics/edje \
		emotion.0:${PORTSDIR}/multimedia/emotion \
		esmart_trans_x11.0:${PORTSDIR}/graphics/esmart \
		evas.1:${PORTSDIR}/graphics/evas \
		tag.5:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	pkgconfig libxml2
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
