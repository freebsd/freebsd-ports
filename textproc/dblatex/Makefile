PORTNAME=	dblatex
DISTVERSION=	0.3.12
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}3-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DocBook to LaTeX/ConTeXt Publishing

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${LOCALBASE}/share/texmf-dist/tex/generic/iftex/ifxetex.sty:print/texlive-texmf
RUN_DEPENDS=	docbook-xml>0:textproc/docbook-xml \
		xsltproc:textproc/libxslt

USES=		python:3.5+ tar:bzip2
USE_PYTHON=	autoplist distutils noflavors
PYDISTUTILS_INSTALLARGS+=	--catalogs=${LOCALBASE}/share/xml/catalog.ports \
				--prefix=${PREFIX}
USE_TEX=	dvipsk:run tex

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/SHELL_SCRIPT/ s|#!.*|#!${PYTHON_CMD}|' ${WRKSRC}/setup.py

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/pdfdocs),/d ; /htmldoc)/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
