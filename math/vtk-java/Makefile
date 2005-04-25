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
BINARIES=	vtkParseJava vtkWrapJava

USE_JAVA=       yes
JAVA_VERSION=   1.4+
JAVA_OS=        native
JAVA_BUILD=     jdk
#USE_JIKES=      no

JARFILE=	vtk.jar	#	${PORTNAME}.jar
DESTJARFILE=	vtk.jar #	${PORTNAME}.jar
CMAKE_DEFS+=	-DVTK_WRAP_JAVA:BOOL=ON \
		-DJAVA_ARCHIVE:FILEPATH=${JAR} \
		-DJAVA_AWT_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
		-DJAVA_AWT_LIBRARY:FILEPATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
		-DJAVA_COMPILE:FILEPATH="${JAVAC}" \
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

post-patch: patch-common

post-build:
	@${ECHO_MSG} "Building Java sources"
	${CP} ${VTKSRCDIR}/Wrapping/Java/vtk/vtkCanvas.java ${WRKSRC}/java/vtk
	${CP} ${VTKSRCDIR}/Wrapping/Java/vtk/vtkPanel.java ${WRKSRC}/java/vtk
	(cd ${WRKSRC}/java;${JAVAC} vtk/*.java)
	(cd ${WRKSRC}/java;${JAR} cvf ${WRKSRC}/bin/${JARFILE} vtk/*.class) 
.if defined(WITH_TESTING)
.for i in AxesActor SimpleVTK TestVTKCanvas TestInternalFrames ImagePlaneWidget TestVTKCanvas
	(cd ${VTKSRCDIR}/Wrapping/Java; \
	${JAVAC} -classpath .:${WRKSRC}/bin/${JARFILE} \
	-d ${WRKSRC}/Wrapping/Java/ ${i}.java) 
.endfor
.endif

do-install: install-cnotice install-binaries install-libs
	@${ECHO_MSG} "Installing ${DESTJARFILE} to ${JAVAJARDIR} ..."
	@${INSTALL_DATA} ${WRKSRC}/bin/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}

.if defined(WITH_TESTING)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${TESTINGDIR}
	@${MKDIR} ${TESTINGDIR}/Java
	@${ECHO_MSG} "Installing Java tests to ${TESTINGDIR}/Java ..."
.for i in AxesActor SimpleVTK TestVTKCanvas TestInternalFrames ImagePlaneWidget
	@${INSTALL_DATA} ${WRKSRC}/Wrapping/Java/${i}*.class ${TESTINGDIR}/Java
	@${INSTALL_DATA} ${VTKSRCDIR}/Wrapping/Java/${i}.java ${TESTINGDIR}/Java
.endfor

	@${ECHO_MSG} "This directory contains VTK Java tests" > ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "To run a SimpleVTK test type:" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "java -classpath .:${PREFIX}/share/java/classes/vtk.jar -Djava.library.path=${PREFIX}/lib SimpleVTK" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "" >> ${TESTINGDIR}/Java/README
	@${ECHO_MSG} "Be shure to use java 1.3 or greater." >> ${TESTINGDIR}/Java/README
.endif

.include <bsd.port.post.mk>
