# New ports collection makefile for:	Ruby-ClibPDF
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	clibpdf
PORTVERSION=	20010519
PORTREVISION=	1
CATEGORIES=	print ruby
MASTER_SITES=	http://www2s.biglobe.ne.jp/~Nori/ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ClibPDF-ALPHA-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby binding for ClibPDF

LIB_DEPENDS=	cpdf.0:${PORTSDIR}/print/clibpdf

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ClibPDF-${PORTVERSION}
INSTALL_TARGET=	site-install

EXAMPLES_EN=	*.rb
EXAMPLES_JA=	ja/*.rb

DOCS_EN=	README
DOCS_JA=	ChangeLog.ja	README.ja	TODO.ja		doc/*

post-extract:
	${MKDIR} ${WRKSRC}/examples/ja
	${MV} ${WRKSRC}/examples/jpntest.rb ${WRKSRC}/examples/ja/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_MODEXAMPLESDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
