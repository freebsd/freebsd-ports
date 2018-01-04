# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	paje
PORTVERSION=	1.97
PORTREVISION=	8
CATEGORIES=	science gnustep
MASTER_SITES=	SF/${PORTNAME}/Releases
DISTNAME=	Paje_${PORTVERSION}
EXTRACT_SUFX=	.tar.gz.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic visualization tool for GNUstep (Gantt chart and more)

LICENSE=	LGPL21

USES=		gnustep
USE_GNUSTEP=	gui base back build

WRKSRC=		${WRKDIR}/${DISTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DOMAIN|#GNUSTEP_INSTALLATION_DOMAIN|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Paje.app/Paje \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/AggregatingFilter.bundle/AggregatingFilter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/ContainerFilter.bundle/ContainerFilter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/EntityTypeFilter.bundle/EntityTypeFilter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/FieldFilter.bundle/FieldFilter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/FileReader.bundle/FileReader \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/General.bundle/General \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/ImbricationFilter.bundle/ImbricationFilter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/OrderFilter.bundle/OrderFilter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/PajeEventDecoder.bundle/PajeEventDecoder \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/PajeSimulator.bundle/PajeSimulator \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/ReductionFilter.bundle/ReductionFilter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/SpaceTimeViewer.bundle/SpaceTimeViewer \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/StatViewer.bundle/StatViewer \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/Paje/StorageController.bundle/StorageController

.include <bsd.port.mk>
