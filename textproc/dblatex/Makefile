# New ports collection makefile for:	dblatex
# Date created:		2007-02-25
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dblatex
PORTVERSION=	0.2.12
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	DocBook to LaTeX/ConTeXt Publishing

BUILD_DEPENDS=	${LOCALBASE}/share/texmf-local/tex/latex/ifxetex/ifxetex.sty:${PORTSDIR}/print/ifxetex
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xml/docbook/4.2/docbook.cat:${PORTSDIR}/textproc/docbook-xml \
		etex:${PORTSDIR}/print/teTeX-base

USE_BZIP2=	yes
USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} \
				--catalogs=${PREFIX}/share/xml/catalog.ports

MAN1=		dblatex.1
MANCOMPRESSED=	yes

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/pdfdocs),/d' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e '/docs\/html/d' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e "s,share/man/man1,man/man1,g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
