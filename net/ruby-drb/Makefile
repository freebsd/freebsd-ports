# New ports collection makefile for:	Ruby-DRb
# Date created:		9 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	drb
PORTVERSION=	1.3.8
CATEGORIES=	net ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/acl.rb:${PORTSDIR}/security/ruby-acl

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	doc/*.rd doc/ja/*.rd.ja

post-extract:
	${MKDIR} ${WRKSRC}/acl/doc ${WRKSRC}/acl/lib ${WRKSRC}/acl/runit
	cd ${WRKSRC}; for f in */acl*; do ${MV} $$f ${WRKSRC}/acl/$$f; done
	${MKDIR} ${WRKSRC}/sample/ja
	${MV} ${WRKSRC}/sample/*.ja ${WRKSRC}/sample/ja/
	${MKDIR} ${WRKSRC}/doc/ja
	${MV} ${WRKSRC}/doc/*.ja ${WRKSRC}/doc/ja/

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${CP} -R ${WRKSRC}/doc/* ${RUBY_MODDOCDIR}/
.endif
