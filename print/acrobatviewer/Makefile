# New ports collection makefile for:    Adobe Acrobar Viewer Version 1.1
# Date created:				4 Febrary 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acrobatviewer
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	print java
DISTFILES=	viewer.bin:1 MRJToolkitStubs.zip:2
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/magic/acrobatviewer/unix/1.x/:1 \
		http://developer.apple.com/samplecode/MRJToolkitStubs/:2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for the PDF files written in Java(TM)

#XXX need info-unzip for archive.zip
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
JAVA_EXTRACT=	yes
NO_BUILD=	yes
SUB_FILES+=	AcrobatViewer
SUB_LIST+=	PORTNAME=${PORTNAME}

# For the end-users this "InstallAnywhere" wizard probably is a great step
# toward Windows-like software installations compared with the traditional
# "make install" paradigm, but for Unix administrators it is a pain to deal
# with. Fortunately, Zero G (author of the InstallAnywhere) does not use a
# proprietary format for archiving files, so it was possible for me to do the
# following dirty hack. If they will provide a better way to centralise
# installations in the next versions of InstallAnywhere then I'll be glad to
# remove all following crap.

BLOCKSIZE=	32768
ARCHSTART=	1
ARCHSIZE=	2749762
ARCHBLOCKS=	84

do-extract:
		@${MKDIR} ${WRKSRC} && \
			cd ${WRKSRC} && \
			dd if=${DISTDIR}/viewer.bin of=archive.zip bs=${BLOCKSIZE} skip=${ARCHSTART} count=${ARCHBLOCKS} 2>/dev/null && \
			${LOCALBASE}/bin/unzip -o -a -j -qq archive.zip
		@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
			${DISTDIR}/MRJToolkitStubs.zip ${EXTRACT_AFTER_ARGS}

post-extract:
		@cd ${WRKDIR}/MRJToolkitStubs/MRJToolkitStubs && \
			${JAR} cmf META-INF/MANIFEST.MF MRJToolkitStubs.jar com && \
			${MV} MRJToolkitStubs.jar ${WRKSRC}

do-install:
		${MKDIR} ${JAVAJARDIR}/${PORTNAME}
		${INSTALL_DATA} ${WRKSRC}/acrobat.jar ${JAVAJARDIR}/${PORTNAME}
		${INSTALL_DATA} ${WRKSRC}/MRJToolkitStubs.jar ${JAVAJARDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}/
		${INSTALL_DATA} ${WRKSRC}/License.pdf ${DOCSDIR}/
		${INSTALL_DATA} ${WRKSRC}/help.pdf ${DOCSDIR}/
.endif
		${INSTALL_SCRIPT} ${WRKDIR}/AcrobatViewer ${PREFIX}/bin/AcrobatViewer

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
