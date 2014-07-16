# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	Genshi
PORTVERSION=	0.6.1052
PORTREVISION=	2
CATEGORIES=	textproc www python
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Python toolkit for stream-based generation of output for the web

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

WRKSRC=		${WRKDIR}/genshi
CONFLICTS=	py-genshi-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
