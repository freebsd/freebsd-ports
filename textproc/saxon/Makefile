# New ports collection makefile for:   saxon
# Date created:                30 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	saxon
PORTVERSION=	6.5.2
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	saxon
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}

MAINTAINER=	fuyuki@mj.0038.net

USE_ZIP=	yes
USE_JAVA=	1.1+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

JAVALIBDIR=	${PREFIX}/share/java/classes
NO_BUILD_DEPENDS_JAVA=	yes

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${JAVALIBDIR}

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
