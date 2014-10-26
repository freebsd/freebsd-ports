# Created by: Peter Johnson <johnson.peter@gmail.com>
# $FreeBSD$

PORTNAME=	dblatex
PORTVERSION=	0.3.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	DocBook to LaTeX/ConTeXt Publishing

BUILD_DEPENDS=	${LOCALBASE}/share/texmf-dist/tex/generic/ifxetex/ifxetex.sty:${PORTSDIR}/print/texlive-texmf
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xml/docbook/4.2:${PORTSDIR}/textproc/docbook-xml

USES=		tar:bzip2 python:2
USE_PYTHON=	distutils autoplist
USE_TEX=	tex

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/pdfdocs),/d' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e '/htmldoc)/d' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e "s,share/man/man1,man/man1,g" ${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--catalogs=${PREFIX}/share/xml/catalog.ports

.include <bsd.port.post.mk>
