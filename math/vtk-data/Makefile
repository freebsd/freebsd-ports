# New ports collection makefile for:    vtk-data
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-data
DISTFILES=	VTKData-${PORTVERSION}.tar.gz

COMMENT=	The Visualization Toolkit examples data

MASTERDIR=	${.CURDIR}/../vtk

MD5_FILE=	${.CURDIR}/distinfo
WRKSRC=		${WRKDIR}/VTKData-release-${PORTVERSION}
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
INSTFILES=	Baseline Data VTKData.readme

do-configure:

do-patch:

do-build:

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${VTKDATAROOT}
	@${ECHO_MSG} "Installing VTKData to ${EXAMPLESDIR} ..."
.for i in ${INSTFILES}
	@cd ${WRKSRC} && \
		${FIND} ${i} -type d -exec ${MKDIR} ${VTKDATAROOT}/{} \; && \
		${FIND} ${i} \! -type d -exec ${INSTALL_DATA} {} ${VTKDATAROOT}/{} \;
.endfor
	@${RMDIR} ${VTKDATAROOT}/Baseline/Common # empty

.include "${MASTERDIR}/Makefile"
.include <bsd.port.post.mk>
