# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-registry
PORTVERSION=	1.0.0
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
GH_COMMIT=	1d16db8

USES=		shebangfix
SHEBANG_FILES=	samples/*.py
python_OLD_CMD=	.*
python_CMD=	${PYTHON_CMD}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYTHON_PY3K_PLIST_HACK=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.TXT ${WRKSRC}/CONTRIBUTORS.TXT ${WRKSRC}/README.txt \
		${WRKSRC}/documentation/* ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/*.py ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
