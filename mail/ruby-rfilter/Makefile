# New ports collection makefile for:	RubyFilter
# Date created:		6 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rfilter
PORTVERSION=	0.12
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.lickey.com/rubyfilter/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rubyfilter-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library for filtering and delivering email to mailboxes

RUN_DEPENDS=	${RUBY_SITELIBDIR}/rmail/parser.rb:${PORTSDIR}/mail/ruby-rmail

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		NEWS README THANKS TODO doc

post-extract:
	${FIND} ${WRKSRC} -name '*~' -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
