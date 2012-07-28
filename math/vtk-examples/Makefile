# New ports collection makefile for:    vtk-examples
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-examples

COMMENT=	Visualization Toolkit: Examples in the C++, Tcl, Python, and Java

RUN_DEPENDS=	${VTKDATAROOT}/VTKData.readme:${PORTSDIR}/math/vtk-data

MASTERDIR=	${.CURDIR}/../vtk

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include "${MASTERDIR}/Makefile"

do-patch:

do-build:

do-install: install-cnotice
	@${ECHO_MSG} "Installing Examples to ${EXAMPLESDIR} ..."
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/Examples
	@cd ${VTKSRCDIR} && \
		${FIND} Examples -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; && \
		${FIND} Examples \! -type d -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${RM} ${EXAMPLESDIR}/Examples/CMakeList*

	@${ECHO_MSG} "Installing Testing to ${EXAMPLESDIR} ... "
	@${MKDIR} ${TESTINGDIR}
.for i in ${VTK_KITS}
	@cd ${VTKSRCDIR}/${i}/Testing && \
		${FIND} * -type d -exec ${MKDIR} ${TESTINGDIR}/${i}/{} \; && \
		${FIND} * \! -type d -exec ${INSTALL_DATA} {} ${TESTINGDIR}/${i}/{} \;
.endfor

	@${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README.examples

.include <bsd.port.post.mk>
