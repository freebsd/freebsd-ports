# Created by: giffunip
# $FreeBSD$

PORTNAME=	laspack
PORTVERSION=	1.12.2
CATEGORIES=	math
MASTER_SITES=	NL/linalg
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Package for solving large sparse systems of linear equations

LICENSE=	LASPACK
LICENSE_FILE=	${WRKSRC}/copyrght.h
LICENSE_NAME=	LASPack license
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile
MAKE_ARGS=	HOME=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/local+${LOCALBASE}+g' ${WRKSRC}/${MAKEFILE}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}

# XXX: test does not work properly (see work/laspack/check/diffs)
do-test:
	cd ${WRKDIR} && ${SETENV} HOME=${WRKDIR} ./install
	cd ${WRKSRC}/check && ${SETENV} HOME=${WRKDIR} ./check

.include <bsd.port.mk>
