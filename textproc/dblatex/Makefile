# New ports collection makefile for:	dblatex
# Date created:		2007-02-25
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dblatex
PORTVERSION=	0.2.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	DocBook to LaTeX/ConTeXt Publishing

RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xml/docbook/4.2/docbook.cat:${PORTSDIR}/textproc/docbook-xml \
		etex:${PORTSDIR}/print/teTeX-base

USE_BZIP2=	yes
USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} \
				--catalogs=${PREFIX}/share/xml/catalog.ports

PORTDOCS=	manual.pdf

MAN1=		dblatex.1
MANCOMPRESSED=	yes

post-patch:
	${REINPLACE_CMD} -e "s,share/man/man1,man/man1,g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
