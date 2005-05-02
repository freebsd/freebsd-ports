# New ports collection makefile for:	kst
# Date created:			Fri Apr 30 17:28:56 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kst
PORTVERSION=	0.99
PORTREVISION=	3
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE} \
		http://omega.astro.utoronto.ca/${PORTNAME}/
MASTER_SITE_SUBDIR=	stable/apps/KDE3.x/scientific

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Data viewing program for KDE

LIB_DEPENDS=	cfitsio.0:${PORTSDIR}/astro/cfitsio \
		gsl.7:${PORTSDIR}/math/gsl

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|xx||g' ${WRKSRC}/po/Makefile.in

.include <bsd.port.mk>
