# New ports collection makefile for:	Ruby-TMail
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tmail
PORTVERSION=	0.9.3
CATEGORIES=	mail ruby
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.xdsl.ne.jp/Cd/aamine/soft/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime \
		${RUBY_SITELIBDIR}/strscan.rb:${PORTSDIR}/devel/ruby-strscan

USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

post-patch:
	${RUBY} -i -ne '/\btmail\b/ and print' \
		${WRKSRC}/ext/PATHCONV ${WRKSRC}/lib/PATHCONV
	for d in cparse cscan; do ${RM} -rf ${WRKSRC}/ext/$$d; done
	for d in amstd raccrt strscan; do ${RM} -rf ${WRKSRC}/lib/$$d; done

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/tmail
	${CP} -R ${WRKSRC}/sample/ ${RUBY_EXAMPLESDIR}/tmail/
	${MKDIR} ${RUBY_DOCDIR}/tmail/ja
	${CP} -R ${WRKSRC}/README.en ${WRKSRC}/doc.en/ ${RUBY_DOCDIR}/tmail/
	${CP} -R ${WRKSRC}/README.ja ${WRKSRC}/doc.ja/ ${RUBY_DOCDIR}/tmail/ja/
.endif

.include <bsd.port.mk>
