# New ports collection makefile for:	koctave
# Date created:				01 August 2003
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	koctave
PORTVERSION=	0.70
PORTREVISION=	2
CATEGORIES=	math kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDEGUI for octave

RUN_DEPENDS=	octave:${PORTSDIR}/math/octave

USE_QT_VER=	3
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	${REINPLACE_CMD} -e '/kde_appsdir/s|applnk||g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/kde_appsdir/s|Applications|applications/kde|g' \
		-e '/kde_appsdir/s|share/||g' ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/src/prefs.cpp ${WRKSRC}/src/koctave.cpp

.include <bsd.port.mk>
