# New ports collection makefile for:	freenet
# Date created:				Thu May  1 20:19:56 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freenet
PORTVERSION=	0.5.2.1.5102
CATEGORIES=	net java security
MASTER_SITES=	http://freenetproject.org/snapshots/
DISTNAME=	${PORTNAME}-20050315
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Peer-to-peer network aiming at anonymity and freedom of speech

BROKEN=		Unfetchable

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

JAVAVM=		${LOCALBASE}/bin/java
#
DATA_FILES=	seednodes.ref
DOC_FILES=	README
JAR_FILES=	freenet.jar freenet-ext.jar
# jar startup file
JAR_START=	freenet.jar
# seed file
SEED_FILE=	seednodes.ref

PORTDOCS=	${DOC_FILES}

PLIST_FILES=	\
		bin/${PORTNAME:L} \
		%%DATADIR%%/seednodes.ref \
		%%JAVAJARDIR%%/freenet-ext.jar \
		%%JAVAJARDIR%%/freenet.jar
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%DATA_DIR%%|${DATADIR:S,^${PREFIX}/,,}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAVAJARDIR%%|${JAVAJARDIR:S,^${PREFIX}/,,}|; \
		s|%%JAR_FILES%%|${JAR_FILES}|; \
		s|%%JAR_START%%|${JAR_START}|; \
		s|%%SEED_FILE%%|${SEED_FILE}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
# data
	@${MKDIR} ${DATADIR}
.for file in ${DATA_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
# jar
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${jar} ${JAVAJARDIR}
.endfor
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
