# New ports collection makefile for:	XNap
# Date created:				Mon Nov 19 22:02:27 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XNap
DISTVERSION=	2.5r3
PORTREVISION=	3
CATEGORIES=	net-p2p audio java
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/2.5r3
#DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/-pre/:S/.b/-beta/}
DISTNAME=	${PORTNAME:L}-${DISTVERSION}

MAINTAINER=	conrads@cox.net
COMMENT=	Pure Java napster client; also, supports OpenNap & giFT (FastTrack)

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

JAVAVM=		${LOCALBASE}/bin/java

DOC_FILES=	AUTHORS COPYING COPYING.LIB NEWS README \
		TODO
PORTDOCS=	${DOC_FILES}

PLIST_FILES=	\
		bin/${PORTNAME:L} \
		%%JAVAJARDIR%%/${PORTNAME:L}.jar

post-patch:
	@${SED} -e "s|%%JAVAJARDIR%%|${JAVAJARDIR:S,^${PREFIX}/,,}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_DATA} ${WRKSRC}/xnap.jar \
		${JAVAJARDIR}/${PORTNAME:L}.jar
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
