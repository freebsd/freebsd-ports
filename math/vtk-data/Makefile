# New ports collection makefile for:    vtk-data
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-data
DISTFILES=	VTKData-${PORTVERSION}-cvs${CVSDATE}.tar.gz

COMMENT=	The Visualization Toolkit examples data

BROKEN=		Unfetchable

MASTERDIR=	${.CURDIR}/../vtk

MD5_FILE=	${.CURDIR}/distinfo
WRKSRC=		${WRKDIR}/VTKData
PKGMESSAGE=	${.CURDIR}/pkg-message

do-configure:

do-patch:

do-build:

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${VTKDATAROOT}
	@${ECHO_MSG} "Installing VTKData to ${EXAMPLESDIR} ..."
	@${CP} -R ${WRKSRC}/* ${VTKDATAROOT}

.include "${MASTERDIR}/Makefile"
.include <bsd.port.post.mk>
