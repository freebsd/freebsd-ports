# New ports collection makefile for:    vtk-examples
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-examples

COMMENT=	Visualization Toolkit: Examples in the C++, Tcl, Python and Java

RUN_DEPENDS=	${VTKDATAROOT}/VTKData.readme:${PORTSDIR}/math/vtk-data

MASTERDIR=	${.CURDIR}/../vtk

PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"

do-build:

do-install: install-cnotice
	@${ECHO_MSG} "Installing Examples to ${EXAMPLESDIR} ..."
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/Examples
	@${CP} -R ${VTKSRCDIR}/Examples/* ${EXAMPLESDIR}/Examples
	@${RM} ${EXAMPLESDIR}/Examples/CMakeList*

	@${ECHO_MSG} "Installing Testing to ${EXAMPLESDIR} ... "
	@${MKDIR} ${TESTINGDIR}
.for i in ${VTK_KITS}
	@${MKDIR} ${TESTINGDIR}/${i}
	@${CP} -R ${VTKSRCDIR}/${i}/Testing/* ${TESTINGDIR}/${i}
.endfor

	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' > ${EXAMPLESDIR}/BUILD-HOWTO
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' > ${DOCSDIR}/README.examples

.include <bsd.port.mk>
