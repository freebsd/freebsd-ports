# New ports collection makefile for:	Ruby/RSS (alternative impl.)
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rss
PORTVERSION=	0.0.7
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	.alt
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby library for handling RSS (alternative impl.)

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv \
		${RUBY_SITELIBDIR}/xmlscan/parser.rb:${PORTSDIR}/textproc/ruby-xmlscan
# You can use ruby-xmlparser as an alternative to xmlscan:
#		${RUBY_SITEARCHLIBDIR}/xmlparser.so:${PORTSDIR}/textproc/ruby-xmlparser
# You can use REXML as an alternative to xmlscan, but 2.5.0 or later only:
#		${RUBY_SITELIBDIR}/rexml/document.rb:${PORTSDIR}/textproc/ruby-rexml

CONFLICTS=	ruby-rss-*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS_EN=	README.en Tutorial.en
DOCS_JA=	README.ja Tutorial.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
