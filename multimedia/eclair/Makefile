# New ports collection makefile for:	eclair
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	eclair
PORTVERSION=	20060926
CATEGORIES=	multimedia
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An EFL powered media player

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig libxml2
USE_EFL=	ecore edje evas emotion
USE_EFL_ESMART=	trans_x11
USE_SQLITE=	3

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
