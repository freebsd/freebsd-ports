# New ports collection makefile for:	Ruby-ERb
# Date created:		21 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	erb
PORTVERSION=	1.3.3
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

post-extract:
		${MKDIR} ${WRKSRC}/sample/ja
		${MV} ${WRKSRC}/sample/sample.rhtml ${WRKSRC}/sample/ja

post-patch:
		${RUBY} -i -pe '$$. == 1 and $$_ = "#!${RUBY}\n" + $$_' \
			${WRKSRC}/lib/erb/erb.rb

do-install:
	@cd ${WRKSRC}; \
	${RUBY} install.rb
	${LN} -s ${RUBY_SITELIBDIR}/erb/erb.rb ${PREFIX}/bin/erb
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/sample ${RUBY_EXAMPLESDIR}/erb/
.endif

.include <bsd.port.mk>
