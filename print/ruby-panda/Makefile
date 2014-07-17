# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	panda
PORTVERSION=	0.0.7
PORTREVISION=	5
CATEGORIES=	print ruby
MASTER_SITES=	http://www2s.biglobe.ne.jp/~Nori/ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby extension library to access Panda

BROKEN=		not staged

LIB_DEPENDS=	libpanda.so:${PORTSDIR}/print/panda \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	site-install

DOCS_EN=	README	\
		doc/ref_en.html	doc/ref_en.rd
DOCS_JA=	ChangeLog.ja	README.ja	TODO.ja	\
		doc/ref_ja.html	doc/ref_ja.rd
EXAMPLES_EN=	circles.rb	main.rb		morecircles.rb	template.rb

NO_STAGE=	yes
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
