PORTNAME=	presenterm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.1
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Markdown terminal slideshow tool
WWW=		https://mfontanini.github.io/presenterm/

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE MIT MPL20 ZLIB
LICENSE_COMB=	multi

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo python:env
USE_GITHUB=	yes
GH_ACCOUNT=	mfontanini

OPTIONS_DEFINE=		D2 DOCS EXAMPLES LATEX WEASYPRINT
OPTIONS_DEFAULT=	LATEX WEASYPRINT

D2_DESC=		D2 diagrams support
WEASYPRINT_DESC=	Export PDF via weasyprint

D2_RUN_DEPENDS=		d2:graphics/d2
LATEX_RUN_DEPENDS=	pandoc:textproc/hs-pandoc \
			typst:textproc/typst
WEASYPRINT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}weasyprint>=61.2:print/py-weasyprint@${PY_FLAVOR}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.sample.yaml ${STAGEDIR}${ETCDIR}/config.yaml.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/src && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/docs/src && \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
