# New ports collection makefile for:	Ruby-TMail
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tmail
PORTVERSION=	0.9.7
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.loveruby.net/archive/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime \
		${RUBY_SITELIBDIR}/strscan.rb:${PORTSDIR}/devel/ruby-strscan

USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

CONFIGURE_ARGS=	--with=ext/b64,ext/mails,lib/tmail

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/ ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${CP} -R ${WRKSRC}/README.en ${WRKSRC}/doc.en/ ${RUBY_DOCDIR}/${PORTNAME}/
	${CP} -R ${WRKSRC}/README.ja ${WRKSRC}/doc.ja/ ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endif

.include <bsd.port.mk>
