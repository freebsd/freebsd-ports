# New ports collection makefile for:   beepcore-java
# Date created:                14 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	beepcore
PORTVERSION=	0.9.07
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	java-
EXTRACT_SUFX=	.tgz

MAINTAINER=	fuyuki@hadaly.org
COMMENT=	An implementation of BEEP core and BEEP mapping for TCP in Java

RUN_DEPENDS=	${LOCALBASE}/share/java/classes/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j

USE_JAVA=	1.3+
NO_BUILD=	yes

NO_BUILD_DEPENDS_JAVA=	yes
JAVALIBDIR=	${PREFIX}/share/java/classes

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/beep*.jar ${JAVALIBDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/example.jar ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/* ${EXAMPLESDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/*.htm ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
