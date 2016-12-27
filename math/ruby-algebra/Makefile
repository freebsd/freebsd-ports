# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	algebra
PORTVERSION=	0.72
CATEGORIES=	math ruby
MASTER_SITES=	http://blade.nagaokaut.ac.jp/~sinara/ruby/math/algebra/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for mathematical (algebraic) computations

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes

DEPRECATED=	Use rubygem-algebra instead
EXPIRATION_DATE=	2017-01-28

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} *.html *.rd ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/doc-ja/ && ${INSTALL_DATA} *.html *.rd ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample/sample-* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
