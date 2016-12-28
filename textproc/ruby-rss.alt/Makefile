# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rss
PORTVERSION=	0.2.6
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	.alt
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for handling RSS (alternative impl.)

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	ja-${RUBY_PKGNAMEPREFIX}uconv>=0:japanese/ruby-uconv

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

CONFLICTS_INSTALL=	ruby-rss-*

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS_EN=	README.en Tutorial.en
DOCS_JA=	README.ja Tutorial.ja

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_EN} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_JA} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
