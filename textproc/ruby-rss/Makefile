# New ports collection makefile for:	Ruby/RSS
# Date created:		10 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rss
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.chadfowler.com/ruby/rss/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby library for parsing, creating, downloading, and caching RSS

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmlparser.so:${PORTSDIR}/textproc/ruby-xmlparser

CONFLICTS=	ruby-rss.alt-*

USE_RUBY=	yes

NO_BUILD=	yes
INSTALL_TARGET=	site-install

RUBY_SHEBANG_FILES=	${WRKSRC}/rssdrb.rb ${WRKSRC}/samples/rsstest.rb
DOCS=		ChangeLog README

do-install:
	${INSTALL_DATA} ${WRKSRC}/rss*.rb ${RUBY_SITELIBDIR}/
	${CHMOD} +x ${RUBY_SITELIBDIR}/rssdrb.rb
	${LN} -fs ${RUBY_SITELIBDIR}/rssdrb.rb ${PREFIX}/sbin/
	${LN} -fs rssdrb.rb ${PREFIX}/sbin/rssdrb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
