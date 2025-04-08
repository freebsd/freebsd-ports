PORTNAME=	tagsoup
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	http://vrici.lojban.org/~cowan/tagsoup/
EXTRACT_SUFX=	.jar

MAINTAINER=	java@FreeBSD.org
COMMENT=	SAX-compliant parser written in Java
WWW=		http://vrici.lojban.org/~cowan/tagsoup

LICENSE=	APACHE20

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar \
		${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar

do-extract:
	@${DO_NADA}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}.jar \
	    ${STAGEDIR}${JAVAJARDIR}
	${RLN} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar \
	    ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
