# New ports collection makefile for:   beepcore-java
# Date created:                14 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	beepcore
PORTVERSION=	0.9.08
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	SF/${PORTNAME}-java/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	java-
EXTRACT_SUFX=	.tgz

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	An implementation of BEEP core and BEEP mapping for TCP in Java

RUN_DEPENDS=	${JAVALIBDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/beep*.jar ${JAVAJARDIR}
	cd ${WRKSRC}/example \
	  && ${FIND} -s . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} -s . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/lib/example.jar ${EXAMPLESDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/*.htm ${DOCSDIR}/
.endif

.include <bsd.port.mk>
