# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	beepcore
PORTVERSION=	0.9.08
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	SF/${PORTNAME}-java/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	java-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of BEEP core and BEEP mapping for TCP in Java

RUN_DEPENDS=	${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/beep*.jar ${STAGEDIR}${JAVAJARDIR}
	(cd ${WRKSRC}/example \
	  && ${FIND} -s . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/{} \; \
	  && ${FIND} -s . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/{} \;)
	${INSTALL_DATA} ${WRKSRC}/lib/example.jar ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/*.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
