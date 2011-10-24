# New ports collection makefile for:	Ruby/RSS (alternative impl.)
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rss
PORTVERSION=	0.2.4
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	.alt
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby library for handling RSS (alternative impl.)

RUN_DEPENDS=	${LOCALBASE}/${SADIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv

CONFLICTS=	ruby-rss-*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	rexml
SADIR=	lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

DOCS_EN=	README.en Tutorial.en
DOCS_JA=	README.ja Tutorial.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${DOCS_JA:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
