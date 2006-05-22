# New ports collection makefile for:   asciidoc
# Date created:        9 Feb 2006
# Whom:                anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	asciidoc
PORTVERSION= 	7.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.methods.co.nz/asciidoc/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	A text document format for writing short documents and man pages

USE_PYTHON=	yes

NO_BUILD=	yes

MAN1=		a2x.1 asciidoc.1

pre-patch:
	${REINPLACE_CMD} \
		-e "s|/bin/bash|/usr/bin/env bash|g" \
		-e "s|/etc/asciidoc|${PREFIX}/etc/asciidoc|g" \
		${WRKSRC}/a2x
	${REINPLACE_CMD} \
		-e "s|/etc/asciidoc|${PREFIX}/etc/asciidoc|g" \
		${WRKSRC}/asciidoc.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciidoc.py ${PREFIX}/bin/asciidoc
	${INSTALL_SCRIPT} ${WRKSRC}/a2x ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/asciidoc
	${INSTALL_DATA} ${WRKSRC}/*.conf ${PREFIX}/etc/asciidoc
	${MKDIR} ${PREFIX}/etc/asciidoc/filters
	${INSTALL_DATA} ${WRKSRC}/filters/code-filter.conf \
		${PREFIX}/etc/asciidoc/filters
	${INSTALL_SCRIPT} ${WRKSRC}/filters/code-filter.py \
		${PREFIX}/etc/asciidoc/filters
	${MKDIR} ${PREFIX}/etc/asciidoc/docbook-xsl
	${INSTALL_DATA} ${WRKSRC}/docbook-xsl/*.xsl \
		${PREFIX}/etc/asciidoc/docbook-xsl
	${MKDIR} ${PREFIX}/etc/asciidoc/stylesheets
	${INSTALL_DATA} ${WRKSRC}/stylesheets/*.css \
		${PREFIX}/etc/asciidoc/stylesheets
	${MKDIR} ${PREFIX}/etc/asciidoc/images/icons/callouts
	${INSTALL_DATA} ${WRKSRC}/images/icons/*.png \
		${PREFIX}/etc/asciidoc/images/icons
	${INSTALL_DATA} ${WRKSRC}/images/icons/callouts/* \
		${PREFIX}/etc/asciidoc/images/icons/callouts
	${INSTALL_MAN} ${WRKSRC}/doc/a2x.1 ${WRKSRC}/doc/asciidoc.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>
