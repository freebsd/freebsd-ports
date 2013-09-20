# Created by: gahr
# $FreeBSD$

PORTNAME=	vtk
PORTVERSION=	5.10.1
CATEGORIES=	math graphics
MASTER_SITES=	http://www.vtk.org/files/release/${PORTVERSION:R}/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/
PKGNAMESUFFIX=	-data
DISTNAME=	vtkdata-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The Visualization Toolkit test and example data

LATEST_LINK=	vtk5-data

WRKSRC=		${WRKDIR}/VTKData${PORTVERSION}

NO_BUILD=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/VTKData

.include <bsd.port.mk>
