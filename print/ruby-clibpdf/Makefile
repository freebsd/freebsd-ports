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
PKGNAMEPREFIX=	ruby-
DISTNAME=	ClibPDF-ALPHA-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	cpdf.0:${PORTSDIR}/print/clibpdf
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-opt-dir="${LOCALBASE}"

WRKSRC=		${WRKDIR}/ClibPDF-${PORTVERSION}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

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

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/clibpdf/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${PREFIX}/share/examples/ruby/clibpdf/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${PREFIX}/share/examples/ruby/clibpdf/ja/
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/clibpdf/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/clibpdf/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/clibpdf/ja/
.endfor
.endif

.include <bsd.port.mk>
