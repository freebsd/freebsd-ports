# Created by: ijliao
# $FreeBSD$

PORTNAME=	pipe
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	misc java
MASTER_SITES=	SF/${PORTNAME}2/Pipe%202/PIPE2%20V${PORTVERSION}
DISTNAME=	pipe25_rc5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for creating and analysing Petri nets

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes

SUB_FILES=	pipe.sh

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pipe.sh ${STAGEDIR}${PREFIX}/bin/pipe
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	cd ${WRKSRC}/Docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/javadoc

.include <bsd.port.mk>
