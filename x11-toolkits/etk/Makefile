# New ports collection makefile for:	etk
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	etk
PORTVERSION=	0.1.0.042
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A comprehensive toolkit based on the EFL

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas ecore edje
USE_EFL_ECORE=	file x11 imf imf_evas
USE_EFL_EVAS_LOADERS=	png jpeg
USE_LDCONFIG=	yes

# NLS is mandatory
USE_GETTEXT=	yes
LDFLAGS=	"-lintl"

.include <bsd.port.mk>
