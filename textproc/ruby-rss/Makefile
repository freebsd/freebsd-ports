# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rss
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.chadfowler.com/ruby/rss/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for parsing, creating, downloading, and caching RSS

OPTIONS_DEFINE=	DOCS EXAMPLES

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmlparser.so:textproc/ruby-xmlparser

CONFLICTS=	ruby-rss.alt-*

USE_RUBY=	yes
USES=		shebangfix

NO_BUILD=	yes
INSTALL_TARGET=	site-install

SHEBANG_FILES=	${WRKSRC}/rssdrb.rb ${WRKSRC}/samples/rsstest.rb
DOCS=		ChangeLog README

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/rss*.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${CHMOD} +x ${STAGEDIR}${RUBY_SITELIBDIR}/rssdrb.rb
	${LN} -fs ${RUBY_SITELIBDIR}/rssdrb.rb ${STAGEDIR}${PREFIX}/sbin/
	${LN} -fs rssdrb.rb ${STAGEDIR}${PREFIX}/sbin/rssdrb
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
