# New ports collection makefile for:   jing
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jing
PORTVERSION=	2003.06.19
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A RELAX NG validator in Java

USE_ZIP=	yes
USE_JAVA=	1.4+
NO_BUILD=	yes

NO_BUILD_DEPENDS_JAVA=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/jing.jar ${JAVAJARDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
