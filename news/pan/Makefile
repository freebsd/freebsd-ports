# New ports collection makefile for:	pan
# Date created:				07 August 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	pan
PORTVERSION=	0.11.4
PORTREVISION=	1
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/SOURCE/ \
		http://pan.rebelbase.com/download/obsolete/${PORTVERSION}/SOURCE/ \
		${MASTER_SITE_GNOME}
		
MASTER_SITE_SUBDIR=	sources/pan/0.11
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GNOME newsreader based on Agent for Windows

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex -lcompat"
CONFIGURE_ARGS=	--enable-html
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
