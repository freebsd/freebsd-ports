# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	medusa
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	net devel python
MASTER_SITES=	CHEESESHOP/source/m/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asynchronous socket-based server framework for Python

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in CHANGES.txt INSTALL.txt LICENSE.txt README.txt TODO.txt
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for exdir in demo test thread
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${exdir} ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
