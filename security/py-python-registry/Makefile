# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-registry
PORTVERSION=	1.0.3
CATEGORIES=	security devel python
MASTER_SITES=	GH \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Read access to Windows Registry files

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	williballenthin
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	24afb86

USES=		shebangfix
SHEBANG_FILES=	samples/*.py
python_OLD_CMD=	.*
python_CMD=	${PYTHON_CMD}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

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
