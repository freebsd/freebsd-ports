# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	labplot
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	math kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data plotting and function analysis tool for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		cmake shared-mime-info tar:bzip2
USE_XORG=	xft xpm
USE_GCC=	yes
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|i->\(children<T>\)|\1|' \
		${WRKSRC}/src/backend/core/AbstractAspect.h
	@${REINPLACE_CMD} -e \
		's|!isnan|!std::isnan|' \
		${WRKSRC}/src/backend/worksheet/plots/cartesian/CartesianCoordinateSystem.cpp

.include <bsd.port.mk>
