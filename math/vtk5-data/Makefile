# Created by: gahr
# $FreeBSD$

PORTNAME=	vtk
PORTVERSION=	5.10.1
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${PORTVERSION:R}/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/
PKGNAMESUFFIX=	5-data
DISTNAME=	vtkdata-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Visualization Toolkit test and example data

WRKSRC=		${WRKDIR}/VTKData${PORTVERSION}

NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/VTKData

.include <bsd.port.mk>
