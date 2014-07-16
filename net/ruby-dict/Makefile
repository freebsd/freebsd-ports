# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	dict
PORTVERSION=	0.9.4
CATEGORIES=	net ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Client-side implementation of the DICT protocol in Ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

RUBY_SHEBANG_FILES=	${WRKSRC}/rdict

DOCS=		Changelog README doc/dict.html doc/rdict.html

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rdict ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
