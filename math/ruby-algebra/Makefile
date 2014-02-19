# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	algebra
PORTVERSION=	0.72
CATEGORIES=	math ruby
MASTER_SITES=	http://blade.nagaokaut.ac.jp/~sinara/ruby/math/algebra/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby library for mathematical (algebraic) computations

USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

DOCS_EN=	doc/*.rd	doc/*.html
DOCS_JA=	doc-ja/*.rd	doc-ja/*.html

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.mk>
