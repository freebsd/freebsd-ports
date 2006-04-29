# New ports collection makefile for:   gnonlin
# Date created:			2 June 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnonlin
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GStreamer extension library for non-linear editing

LIB_DEPENDS=	gstreamer-0.8.5:${PORTSDIR}/multimedia/gstreamer80

CONFLICTS=	pitivi-0.1.1*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnonlin-config.1

.include <bsd.port.mk>
