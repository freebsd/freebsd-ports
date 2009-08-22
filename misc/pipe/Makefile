# ex:ts=8
# Ports collection makefile for:	pipe
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pipe
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	misc java
MASTER_SITES=	SF/${PORTNAME}2/Pipe%202/PIPE2%20V${PORTVERSION}
DISTNAME=	pipe25_rc5

MAINTAINER=	stefan@fh-mainz.de
COMMENT=	A tool for creating and analysing Petri nets

USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+

PLIST_FILES=	bin/pipe
SUB_FILES=	pipe.sh

.if !defined(NOPORTDOCS)
PORTDOCS=*
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pipe.sh ${PREFIX}/bin/pipe
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/Docs && \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/javadoc/{} \;
	cd ${WRKSRC}/Docs && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/javadoc/{} \;
.endif

.include <bsd.port.mk>
