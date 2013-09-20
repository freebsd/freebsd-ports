# Created by: giffunip
# $FreeBSD$

PORTNAME=	laspack
PORTVERSION=	1.12.2
CATEGORIES=	math
MASTER_SITES=	NL
MASTER_SITE_SUBDIR=	linalg
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Package for solving large sparse systems of linear equations

WRKSRC=	${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile
MAKE_ENV+=	HOME=${PREFIX}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's+/usr/local+${LOCALBASE}+g' ${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
.endif

.ifdef MAINTAINER_MODE
regression-test:
	@cd ${WRKDIR} && ${SETENV} HOME=${WRKDIR} ./install
	@cd ${WRKSRC}/check && ${SETENV} HOME=${WRKDIR} ./check
.endif

.include <bsd.port.mk>
