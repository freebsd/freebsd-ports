# New ports collection makefile for:	Ruby-DRb
# Date created:		9 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	drb
PORTVERSION=	1.3.4.2
CATEGORIES=	net ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/acl.rb:${PORTSDIR}/security/ruby-acl

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

post-extract:
	${MKDIR} ${WRKSRC}/acl/doc ${WRKSRC}/acl/lib ${WRKSRC}/acl/runit
	cd ${WRKSRC} && for f in */acl*; do ${MV} $$f ${WRKSRC}/acl/$$f; done
	${MKDIR} ${WRKSRC}/sample/ja
	${MV} ${WRKSRC}/sample/*.ja ${WRKSRC}/sample/ja/

post-patch:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && for f in drb-ref.rd*; do \
		${MV} $$f $$f.orig; \
		( ${ECHO} '=begin'; ${CAT} $$f.orig; ${ECHO} '=end' ) > $$f; \
		${RM} $$f.orig; \
	done
.endif

do-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && for f in *.rd; do \
		${RUBY_RD} $$f > `${ECHO} $$f | ${SED} 's/\.rd$$/.html/'`; \
	done
	cd ${WRKSRC}/doc && for f in *.rd.ja; do \
		${RUBY_RD} $$f > `${ECHO} $$f | ${SED} 's/\.rd.ja$$/.ja.html/'`; \
	done
	${MKDIR} ${WRKSRC}/doc/ja
	cd ${WRKSRC}/doc && ${MV} *.rd.ja *.ja.html ja/
.endif

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${CP} -R ${WRKSRC}/doc/* ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
