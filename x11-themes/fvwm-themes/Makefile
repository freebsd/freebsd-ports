# Created by: Oyvind Albrigtsen
# $FreeBSD$

PORTNAME=	fvwm-themes
PORTVERSION=	0.7.0
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-extra-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for the Fvwm2 window manager

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		fvwm2:${PORTSDIR}/x11-wm/fvwm2
RUN_DEPENDS=	fvwm2:${PORTSDIR}/x11-wm/fvwm2

USE_XORG=	xpm
USES=		perl5 gmake tar:bzip2
GNU_CONFIGURE=	yes

post-install:
	@cd ${WRKDIR}/${PORTNAME}-extra-${PORTVERSION} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${PREFIX}/share/fvwm/themes

.include <bsd.port.mk>
