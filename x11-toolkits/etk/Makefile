# New ports collection makefile for:	etk
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	etk
PORTVERSION=	20070223
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A comprehensive toolkit based on the EFL

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas ecore edje
USE_LDCONFIG=	yes
# NLS is mandatory
USE_GETTEXT=	yes
LDFLAGS=	"-lintl"

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
