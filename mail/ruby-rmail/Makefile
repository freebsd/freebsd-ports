# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rmail
PORTVERSION=	0.17
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.lickey.com/rubymail/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rubymail-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Lightweight mail manipulating library for Ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		NEWS NOTES README THANKS TODO doc

OPTIONS_DEFINE=	DOCS

post-extract:
	${FIND} ${WRKSRC} -name '*~' -delete

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
