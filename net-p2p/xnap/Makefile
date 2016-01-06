# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XNap
DISTVERSION=	2.5r3
PORTREVISION=	3
CATEGORIES=	net-p2p audio java
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/2.5r3
#DISTNAME=	${PORTNAME:tl}-${PORTVERSION:S/.p/-pre/:S/.b/-beta/}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Java napster client; also, supports OpenNap & giFT (FastTrack)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

JAVAVM=		${LOCALBASE}/bin/java

PORTDOCS=	AUTHORS COPYING COPYING.LIB NEWS README TODO

PLIST_FILES=	bin/${PORTNAME:tl} \
		%%JAVAJARDIR%%/${PORTNAME:tl}.jar

OPTIONS_DEFINE=	DOCS

post-patch:
	@${SED} -e "s|%%JAVAJARDIR%%|${JAVAJARDIR:S,^${PREFIX}/,,}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/xnap.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME:tl}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
