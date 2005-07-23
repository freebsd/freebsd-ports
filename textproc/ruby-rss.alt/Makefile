# New ports collection makefile for:	Ruby/RSS (alternative impl.)
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rss
PORTVERSION=	0.0.8
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	.alt
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby library for handling RSS (alternative impl.)

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
# You can use ruby-xmlscan as an alternative XML parser to REXML:
#		${RUBY_SITEARCHLIBDIR}/xmlparser.so:${PORTSDIR}/textproc/ruby-xmlparser
# Or ruby-xmlparser:
#		${RUBY_SITELIBDIR}/xmlscan/parser.rb:${PORTSDIR}/textproc/ruby-xmlscan

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

CONFLICTS=	ruby-rss-*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	rexml

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
