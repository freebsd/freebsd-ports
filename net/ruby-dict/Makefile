# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	dict
PORTVERSION=	0.9.4
CATEGORIES=	net ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client-side implementation of the DICT protocol in Ruby

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USE_RUBY=	yes
USES=		shebangfix
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

SHEBANG_FILES=	${WRKSRC}/rdict

DOCS=		Changelog README doc/dict.html doc/rdict.html

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rdict ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
