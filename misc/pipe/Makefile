# ex:ts=8
# Ports collection makefile for:	pipe
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pipe
PORTVERSION=	0.b.1.5
CATEGORIES=	misc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	petri-net
DISTNAME=	${PORTNAME}-beta-1.5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform Independent Petri-Net Editor

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+

PLIST_FILES=	bin/pipe
SUB_FILES=	pipe.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	javadoc license manual
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pipe.sh ${PREFIX}/bin/pipe
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/bin && \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC}/bin && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${LN} -s ${DATADIR}/petri-nets ${DATADIR}/Example\ nets
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/resources && \
		${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/resources && \
		${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
