# Ports collection makefile for:	JavaCC
# Date Created:				6 May 2002
# Whom:					Andy Gerweck <gerweck@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	javacc
PORTVERSION=	2.1
CATEGORIES=	textproc java devel
MASTER_SITES=	# Must accept license agreement. :(
DISTNAME=	JavaCC2_1

MAINTAINER=	gerweck@yahoo.com

USE_ZIP=	yes
USE_JAVA=	1.1+

JAVA_CLASSDIR=	${PREFIX}/share/java/classes/
DOC_DIR=	${PREFIX}/share/doc/javacc
EXAMPLES_DIR=	${PREFIX}/share/examples/javacc

RESTRICTED=	"Redistribution of distfiles prohibited."

.if defined(BATCH) || defined (PACKAGE_BUILDING)
IGNORE= "JavaCC may not be redistributed."
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOWNLOAD_URL?=	http://www.webgain.com/products/java_cc/

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the JavaCC ${PORTVERSION} distribution \(${DISTNAME}${EXTRACT_SUFX}\) from ${DOWNLOAD_URL}. Please place the distribution file into ${DISTDIR} and then run make again."
.endif

post-extract:
	@echo
	@echo '********************************************************'
	@echo '**              Running JavaCC Installer              **'
	@echo '**                IMPORTANT DIRECTIONS                **'
	@echo '**                                                    **'
	@echo '** You  must  accept  the  license  and   leave   the **'
	@echo '** installation directory as its default.  This  port **'
	@echo '** will then place the  distributed  files  into  the **'
	@echo '** standard FreeBSD file hierarchy.                   **'
	@echo '********************************************************'
	@echo

	cd ${WRKSRC} && ${JAVA} -cp . ${DISTNAME} -c

do-install:
	${MKDIR} ${JAVA_CLASSDIR}
	for f in javacc jjdoc jjtree; do \
		${PERL} -pe 's(${WRKSRC}/javacc2.1/bin/lib/JavaCC.zip)(${JAVA_CLASSDIR}/JavaCC.jar)o' ${WRKSRC}/javacc2.1/bin/$$f > ${WRKSRC}/tmp; \
		${INSTALL_SCRIPT} ${WRKSRC}/tmp ${PREFIX}/bin/$$f; \
	done
	${INSTALL_DATA} ${WRKSRC}/javacc2.1/bin/lib/JavaCC.zip \
		${JAVA_CLASSDIR}/JavaCC.jar
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/javacc2.1/COPYRIGHT ${DOC_DIR}
	${CP} -r ${WRKSRC}/javacc2.1/doc ${DOC_DIR}

	${MKDIR} ${EXAMPLES_DIR}
	${CP} -r ${WRKSRC}/javacc2.1/examples ${EXAMPLES_DIR}
.endif

.include <bsd.port.post.mk>
