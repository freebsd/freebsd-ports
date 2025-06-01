PORTNAME=	beepcore
PORTVERSION=	0.9.08
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	SF/${PORTNAME}-java/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	java-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of BEEP core and BEEP mapping for TCP in Java
WWW=		https://sourceforge.net/projects/beepcore-java/

RUN_DEPENDS=	${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j

USES=		java tar:tgz

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/beep*.jar ${STAGEDIR}${JAVAJARDIR}
	(cd ${WRKSRC}/example \
	  && ${FIND} -s . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/{} \; \
	  && ${FIND} -s . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/{} \;)
	${INSTALL_DATA} ${WRKSRC}/lib/example.jar ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/*.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
