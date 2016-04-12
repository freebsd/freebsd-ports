# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rfilter
PORTVERSION=	0.12
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.lickey.com/rubyfilter/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rubyfilter-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for filtering and delivering email to mailboxes

RUN_DEPENDS=	${RUBY_SITELIBDIR}/rmail/parser.rb:mail/ruby-rmail

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		NEWS README THANKS TODO doc

OPTIONS_DEFINE=	DOCS

post-extract:
	${FIND} ${WRKSRC} -name '*~' -delete

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
