# New ports collection makefile for:	Ruby/WebUnit
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	webunit
PORTVERSION=	20020410
CATEGORIES=	www textproc ruby
MASTER_SITES=	http://www.xpenguin.biz/download/webunit/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-alpha
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/runit/assert.rb:${PORTSDIR}/devel/ruby-unit \
		${RUBY_SITELIBDIR}/html-parser.rb:${PORTSDIR}/textproc/ruby-html-parser \
		${RUBY_SITELIBDIR}/htmlrepair.rb:${PORTSDIR}/textproc/ruby-htmlrepair \
		${RUBY_SITELIBDIR}/htmlsplit.rb:${PORTSDIR}/textproc/ruby-htmlsplit \
		${RUBY_SITELIBDIR}/nqxml/info.rb:${PORTSDIR}/textproc/ruby-nqxml

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

EXAMPLES_EN=	cgi test sample
DOCS_EN=	index-en.html
DOCS_JA=	index-ja.html TIPS-ja.html TODO-ja.sdf

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
