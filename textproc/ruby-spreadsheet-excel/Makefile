# New ports collection makefile for:	Spreadsheet/Excel for Ruby
# Date created:		8 December 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	spreadsheet-excel
PORTVERSION=	0.2.9
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	 rubyspreadsheet
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	spreadsheet-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module to generate Microsoft Excel compatible files

USE_RUBY=	yes

NO_BUILD=	yes

INSTALL_TARGET=	site-install

DOCS=		CHANGES doc/*
EXAMPLES=	test/test.rb

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/spreadsheet
	${INSTALL_DATA} ${WRKSRC}/spreadsheet/*.rb ${RUBY_SITELIBDIR}/spreadsheet/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
