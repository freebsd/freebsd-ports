# Created by: ijliao
# $FreeBSD$

PORTNAME=	pipe
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	misc java
MASTER_SITES=	SF/${PORTNAME}2/Pipe%202/PIPE2%20V${PORTVERSION}
DISTNAME=	pipe25_rc5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for creating and analysing Petri nets

USES=		zip
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	pipe.sh

OPTIONS_DEFINE=	DOCS

PORTDOCS=*

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pipe.sh ${STAGEDIR}${PREFIX}/bin/pipe
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC}/Docs && \
		${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/javadoc/{} \;
	cd ${WRKSRC}/Docs && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/javadoc/{} \;

.include <bsd.port.mk>
