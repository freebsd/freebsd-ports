# Created by: Peter Johnson <johnson.peter@gmail.com>
# $FreeBSD$

PORTNAME=	dblatex
PORTVERSION=	0.3.2
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DocBook to LaTeX/ConTeXt Publishing

BUILD_DEPENDS=	${LOCALBASE}/share/texmf-dist/tex/generic/ifxetex/ifxetex.sty:${PORTSDIR}/print/texlive-texmf
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook-xml>0:${PORTSDIR}/textproc/docbook-xml

USES=		tar:bzip2 python:2
USE_PYTHON=	distutils autoplist
USE_TEX=	tex

PYDISTUTILS_INSTALLARGS+=	--catalogs=${LOCALBASE}/share/xml/catalog.ports

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/pdfdocs),/d ; /htmldoc)/d' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e "s,share/man/man1,man/man1,g" ${WRKSRC}/setup.py

post-install:
	# shebangfix can't be used because dblatex is built from scratch
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PREFIX}/bin/python2|' \
		${STAGEDIR}${PREFIX}/bin/dblatex

.include <bsd.port.mk>
