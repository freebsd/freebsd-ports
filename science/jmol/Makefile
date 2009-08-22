# Ports collection makefile for:	jmol
# Date created:			May 11, 2008
# Whom:				Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	jmol
PORTVERSION=	11.6.17
CATEGORIES=	science java
MASTER_SITES=	SF/${PORTNAME}/Jmol/Version%20${PORTVERSION}:source1 \
		http://jmol.svn.sourceforge.net/viewvc/jmol/trunk/Jmol/selfSignedCertificate/:source2
DISTFILES=	${PORTNAME}-${PORTVERSION}-full.tar.gz:source1 \
		selfSignedCertificate.cer:source2 \
		selfSignedCertificate.store:source2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-full.tar.gz

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open-Source Java Viewer for Chemical Structures in 3D

USE_JAVA=	yes
JAVA_VERSION=	1.5+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
JMOL_FILES=	Jmol.jar JmolApplet.jar JmolApplet0.jar \
		JmolApplet0_Minimize.jar \
		JmolApplet0_Popup.jar JmolApplet0_Quantum.jar \
		JmolApplet0_ReadersCifPdb.jar JmolApplet0_ReadersMolXyz.jar \
		JmolApplet0_ReadersMore.jar JmolApplet0_ReadersXml.jar \
		JmolApplet0_ShapeBio.jar JmolApplet0_ShapeSpecial.jar \
		JmolApplet0_ShapeSurface.jar \
		JmolApplet0_Smiles.jar JmolApplet0_Symmetry.jar \
		JmolApplet0_i18n.jar
JMOL_FILES_EXT=	Jmol.js
SIGN_DIR=	${WRKSRC}/selfSignedCertificate

.if !defined(WITHOUT_COMPILE)
USE_ANT=	yes
ALL_TARGET=	all
.if !defined(NOPORTDOCS)
ALL_TARGET=	main
.endif
.else
NO_BUILD=	yes
.endif

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

post-extract:
	@${MKDIR} ${SIGN_DIR}
	@${CP} ${DISTDIR}/selfSignedCertificate.cer ${SIGN_DIR}
	@${CP} ${DISTDIR}/selfSignedCertificate.store ${SIGN_DIR}

do-install:
.for j in ${JMOL_FILES_EXT}
	${INSTALL_DATA} ${WRKSRC}/${j} ${JAVAJARDIR}
.endfor

.if !defined(WITHOUT_COMPILE)
.for j in ${JMOL_FILES}
	${INSTALL_DATA} ${WRKSRC}/build/${j} ${JAVAJARDIR}
.endfor
.else
.for j in ${JMOL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${j} ${JAVAJARDIR}
.endfor
.endif

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/doc && ${FIND} . -type f -exec \
		${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.post.mk>
