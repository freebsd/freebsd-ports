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

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	${LOCALBASE}/${SADIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv

CONFLICTS=	ruby-rss-*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	rexml
SADIR=	lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

DOCS_EN=	README.en Tutorial.en
DOCS_JA=	README.ja Tutorial.ja

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${DOCS_JA:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
