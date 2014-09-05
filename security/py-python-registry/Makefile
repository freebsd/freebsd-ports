# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-registry
PORTVERSION=	1.0.4
CATEGORIES=	security devel python
MASTER_SITES=	GH \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Read access to Windows Registry files

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	williballenthin
GH_TAGNAME=	86ed1da
GH_COMMIT=	86ed1da

USES=		python shebangfix
USE_PYTHON=	distutils autoplist
SHEBANG_FILES=	samples/*.py
python_OLD_CMD=	.*
python_CMD=	${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 340
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>=0:${PORTSDIR}/devel/py-enum34
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.TXT ${WRKSRC}/CONTRIBUTORS.TXT ${WRKSRC}/README.txt \
		${WRKSRC}/documentation/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
