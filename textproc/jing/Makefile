# New ports collection makefile for:   jing
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jing
PORTVERSION=	2008.10.28
CATEGORIES=	textproc java
MASTER_SITES=	http://jing-trang.googlecode.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	A RELAX NG validator in Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

SUB_FILES=	jing.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jing.sh ${PREFIX}/bin/jing
	${INSTALL_DATA} ${WRKSRC}/bin/jing.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
	cd ${WRKSRC}/doc \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/sample \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.mk>
