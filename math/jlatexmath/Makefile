# New ports collection makefile for:	jlatexmath
# Date created:				11 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	jlatexmath
PORTVERSION=	0.8.9
CATEGORIES=	math java
MASTER_SITES=	http://forge.scilab.org/upload/jlatexmath/files/ \
		http://www.predatorlabs.net/dl/
DISTNAME=	${PORTNAME}-src-all-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Java API to display mathematical formulas written in LaTeX

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_ANT=	yes

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jlatexmath-0.8.9.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
