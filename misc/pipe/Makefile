# ex:ts=8
# Ports collection makefile for:	pipe
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pipe
PORTVERSION=	2.0
CATEGORIES=	misc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pipe2
DISTNAME=	PIPE2_V2_0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform Independent Petri-Net Editor 2

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/Pipe
NO_WRKSUBDIR=	yes
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
	cd ${WRKSRC}/bin && \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC}/bin && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/javadoc/{} \;
	cd ${WRKSRC}/doc && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/javadoc/{} \;
.endif

.include <bsd.port.mk>
