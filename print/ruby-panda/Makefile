# New ports collection makefile for:	Ruby/Panda
# Date created:		28 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	panda
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	print ruby
MASTER_SITES=	http://www2s.biglobe.ne.jp/~Nori/ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension library to access Panda

LIB_DEPENDS=	panda.0:${PORTSDIR}/print/panda \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	site-install

DOCS_EN=	README	\
		doc/ref_en.html	doc/ref_en.rd
DOCS_JA=	ChangeLog.ja	README.ja	TODO.ja	\
		doc/ref_ja.html	doc/ref_ja.rd
EXAMPLES_EN=	circles.rb	main.rb		morecircles.rb	template.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	cd ${RUBY_EXAMPLESDIR}/${PORTNAME}; ${LN} -sf ../../panda/*.jpg ../../panda/*.png ../../panda/*.tif .
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
