# New ports collection makefile for:	eclair
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	eclair
PORTVERSION=	20080223
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An EFL powered media player

LIB_DEPENDS=	tag.6:${PORTSDIR}/audio/taglib

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig libxml2
USE_EFL=	ecore edje evas emotion
USE_EFL_ECORE=	x11 evas file
USE_EFL_ESMART=	draggies
USE_SQLITE=	3

.include <bsd.port.mk>
