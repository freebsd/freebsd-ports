# New ports collection makefile for:	freenet
# Date created:				Thu May  1 20:19:56 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freenet
PORTVERSION=	0.5.2.1.5106
PORTREVISION=	1
CATEGORIES=	net-p2p java security
MASTER_SITES=	http://freenetproject.org/snapshots/ \
		http://downloads.freenetproject.org/ \
		http://fgudin.nerim.net/files/
DISTNAME=	${PORTNAME}-20051123
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Peer-to-peer network aiming at anonymity and freedom of speech

USE_RC_SUBR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DEPRECATED=	Does not work with existing Freenet network
EXPIRATION_DATE=2007-04-22

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
		sbin/${PORTNAME:L} \
		etc/rc.d/${PORTNAME:L}.sh \
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
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/${PORTNAME:L}.sh > ${WRKDIR}/${PORTNAME:L}.sh

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
# rc.d
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME:L}.sh ${PREFIX}/etc/rc.d
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/sbin/${PORTNAME:L}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
