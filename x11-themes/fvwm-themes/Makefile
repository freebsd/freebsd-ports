# New ports collection makefile for:	fvwm-themes
# Date created:				2 February 2001
# Whom:					Oyvind Albrigtsen
#
# $FreeBSD$
#

PORTNAME=	fvwm-themes
PORTVERSION=	0.7.0
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-extra-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@brandon.dvalentine.com
COMMENT=	Themes for the Fvwm2 window manager

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		fvwm2:${PORTSDIR}/x11-wm/fvwm2-devel
RUN_DEPENDS=	fvwm2:${PORTSDIR}/x11-wm/fvwm2-devel

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAN1=		fvwm-themes-config.1 fvwm-themes-menuapp.1 fvwm-themes-com.1 \
		fvwm-themes-images.1 fvwm-themes-start.1 fvwm-themes-root.1

post-install:
	@cd ${WRKDIR}/${PORTNAME}-extra-${PORTVERSION} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/fvwm/themes

.include <bsd.port.mk>
