# New ports collection makefile for:	Ruby/PDFlib
# Date created:		21 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	0.71
PORTREVISION=	1
CATEGORIES=	print ruby
MASTER_SITES=	http://www-nh.scphys.kyoto-u.ac.jp/~thitoshi/ruby/pdflib/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension library to access PDFlib

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		pdf.7:${PORTSDIR}/print/pdflib

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	site-install

RUBY_RD_FILES=	pdflib-api.rd pdflib-api-jp.rd

DOCS_EN=	ChangeLog	README \
		${RUBY_RD_FILES:N*-jp.rd} \
		${RUBY_RD_HTML_FILES:N*-jp.html}
DOCS_JA=	ChangeLog.jp	README.jp \
		${RUBY_RD_FILES:M*-jp.rd} \
		${RUBY_RD_HTML_FILES:M*-jp.html}

EXAMPLES_EN=	hello.rb	pdfclock.rb	pdfgraph.rb \
		pdfimage.rb	text2pdf.rb
EXAMPLES_JA=	jtext2pdf.rb

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_MODEXAMPLESDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
