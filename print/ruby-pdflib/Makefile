# New ports collection makefile for:	Ruby/PDFlib
# Date created:		21 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	0.6
CATEGORIES=	print ruby
MASTER_SITES=	http://www-nh.scphys.kyoto-u.ac.jp/~thitoshi/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	pdf.3:${PORTSDIR}/print/pdflib3 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog	README \
		${RD_DOCS_EN}	${RD_DOCS_EN:S/.rd/.html/}
DOCS_JA=	ChangeLog.jp	README.jp \
		${RD_DOCS_JA}	${RD_DOCS_JA:S/.rd/.html/}
RD_DOCS_EN=	pdflib-api.rd
RD_DOCS_JA=	pdflib-api-jp.rd
EXAMPLES_EN=	hello.rb	pdfclock.rb	pdfgraph.rb \
		pdfimage.rb	text2pdf.rb
EXAMPLES_JA=	jtext2pdf.rb

post-build:
.if !defined(NOPORTDOCS)
.for f in ${RD_DOCS_EN} ${RD_DOCS_JA}
	cd ${WRKSRC}; \
	${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/pdflib/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/pdflib/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/pdflib/ja/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/pdflib/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/pdflib/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/pdflib/ja/
.endfor
.endif

.include <bsd.port.mk>
