# Created by: giffunip
# $FreeBSD$

PORTNAME=	laspack
PORTVERSION=	1.12.2
CATEGORIES=	math
MASTER_SITES=	NL/linalg
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Package for solving large sparse systems of linear equations

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile
MAKE_ARGS=	HOME=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/local+${LOCALBASE}+g' ${WRKSRC}/${MAKEFILE}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}

.ifdef MAINTAINER_MODE
regression-test:
	@cd ${WRKDIR} && ${SETENV} HOME=${WRKDIR} ./install
	@cd ${WRKSRC}/check && ${SETENV} HOME=${WRKDIR} ./check
.endif

.include <bsd.port.mk>
