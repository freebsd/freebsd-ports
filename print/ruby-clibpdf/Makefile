# New ports collection makefile for:	Ruby-ClibPDF
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	clibpdf
PORTVERSION=	19991016
CATEGORIES=	print ruby
MASTER_SITES=	http://www2s.biglobe.ne.jp/~Nori/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ClibPDF-ALPHA-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	cpdf.0:${PORTSDIR}/print/clibpdf

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ClibPDF-${PORTVERSION}
INSTALL_TARGET=	site-install

EXAMPLES_EN=	Arcs.rb		DomainDemo.rb	MarkerTest.rb	Minimal.rb \
		beziertest.rb	charwidth.rb	cover.rb	dashtest.rb \
		filltest.rb	fontlist.rb	helloworld.rb	linkpdfpage.rb \
		outline.rb	textalign.rb	textboxfit.rb	timeaxis.rb \
		weather.rb
EXAMPLES_JA=	jpntest.rb

DOCS_EN=	README
DOCS_JA=	ChangeLog.ja	README.ja	TODO.ja

post-extract:
	${RM} ${WRKSRC}/examples/*.pdf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/clibpdf/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/clibpdf/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/clibpdf/ja/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/clibpdf/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/clibpdf/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/clibpdf/ja/
.endfor
.endif

.include <bsd.port.mk>
