# New ports collection makefile for:    vtk-java
# Date created:         10 Oct 2003
# Whom:                 Mykola Khotyaintsev <ko@irfu.se>
#
# $FreeBSD$
#

CATEGORIES+=	java
PKGNAMESUFFIX=	-java

COMMENT=	VTK Java classes and shared libs

LIB_DEPENDS=	vtkCommon.${LIBVER}:${PORTSDIR}/math/vtk

MASTERDIR=	${.CURDIR}/../vtk

WRAP=		Java
BINARIES=	VTKJavaExecutable vtkParseJava vtkWrapJava

USE_JAVA=	1.4
NEED_JAVAC=	yes
USE_JIKES=	no
JARFILE=	vtk.jar	#	${PORTNAME}.jar
DESTJARFILE=	vtk.jar #	${PORTNAME}.jar
CMAKE_DEFS=	-DVTK_WRAP_JAVA:BOOL=ON \
		-DJAVA_ARCHIVE:FILEPATH=${JAR} \
		-DJAVA_AWT_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
		-DJAVA_AWT_LIBRARY:FILEPATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
		-DJAVA_COMPILE:FILEPATH=${JAVAC} \
		-DJAVA_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
		-DJAVA_INCLUDE_PATH2:PATH=${JAVA_HOME}/include/freebsd

.include "${MASTERDIR}/Makefile"

.ifndef(WITH_TESTING)
pre-everything::
	@${ECHO_MSG} "----------------------- N   O   T   E --------------------------"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to build some Testing Java classes press Ctrl-C now"
	@${ECHO_MSG} "and execute \"make WITH_TESTING=yes\""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "----------------------------------------------------------------"
.endif

do-patch: patch-common

do-install: install-cnotice install-binaries install-libs
	@${ECHO_MSG} "Installing ${DESTJARFILE} to ${JAVAJARDIR} ..."
	@${INSTALL_DATA} ${WRKSRC}/bin/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}

	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${TESTINGDIR}
	@${MKDIR} ${TESTINGDIR}/Java
.if defined(WITH_TESTING)
	@${ECHO_MSG} "Installing Java tests to ${TESTINGDIR}/Java ..."
.for i in AxesActor SimpleVTK Regression TestVTKCanvas TestInternalFrames ImagePlaneWidget
	@${INSTALL_DATA} ${WRKSRC}/Wrapping/Java/${i}*.class ${TESTINGDIR}/Java
	@${INSTALL_DATA} ${VTKSRCDIR}/Wrapping/Java/${i}.java ${TESTINGDIR}/Java
.endfor
.endif

	@${ECHO_MSG} "This directory contains VTK Java tests" > ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "To run a SimpleVTK test type:" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "java -classpath .:${PREFIX}/share/java/classes/vtk.jar -Djava.library.path=${PREFIX}/lib SimpleVTK" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "Be shure to use java 1.3 or greater." >> ${TESTINGDIR}/Java/README

.include <bsd.port.mk>
