# Ports collection makefile for:	JavaCC
# Date Created:				6 May 2002
# Whom:					Andy Gerweck <gerweck@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	javacc
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	textproc java devel
MASTER_SITES=	https://javacc.dev.java.net/files/documents/17/685/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler compiler for Java; includes tools for building syntax trees

FETCH_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_JAVA=	yes
USE_REINPLACE=	yes
FETCH_CMD=	${LOCALBASE}/bin/wget
NO_BUILD=	yes
DISABLE_SIZE=	yes
#DOWNLOAD_URL?=	https://javacc.dev.java.net/servlets/ProjectDocumentList?folderID=212

do-configure:
	for f in "${WRKSRC}/bin/j*"; do \
		${REINPLACE_CMD} -e 's:`dirname \$$0`/lib:${JAVAJARDIR}:' $$f; \
	done

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/lib/javacc.jar ${JAVAJARDIR}
	cd ${WRKSRC}/bin/ && ${INSTALL_SCRIPT} javacc jjdoc jjtree ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
