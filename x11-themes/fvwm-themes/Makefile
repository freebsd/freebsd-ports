# New ports collection makefile for:	fvwm-themes
# Date created:				2 February 2001
# Whom:					Oyvind Albrigtsen
#
# $FreeBSD$
#

PORTNAME=		fvwm-themes
PORTVERSION=		0.6.1
PORTREVISION=		2
CATEGORIES=		x11-wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fvwm-themes
DISTFILES=	fvwm-themes-base-${PORTVERSION}${EXTRACT_SUFX} \
		fvwm-themes-extra-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for the Fvwm2 window manager

BUILD_DEPENDS=	fvwm2:${PORTSDIR}/x11-wm/fvwm2 \
		gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-base-${PORTVERSION}
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

MAN1=		fvwm-themes-config.1 fvwm-themes-menuapp.1 fvwm-themes-com.1 \
		fvwm-themes-images.1 fvwm-themes-start.1

pre-install:
	${MV} ${WRKDIR}/fvwm-themes-extra-${PORTVERSION}/* ${WRKSRC}/themes

.include <bsd.port.mk>
