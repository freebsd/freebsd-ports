# New ports collection makefile for:	Ruby-RDtool
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rdtool
PORTVERSION=	0.6.16
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	RD to HTML/man/etc. converter (RD is to Ruby as POD is to Perl)

BUILD_DEPENDS=	${DEPEND_RUBY_AMSTD} \
		racc:${PORTSDIR}/devel/ruby-racc

USE_RUBY=	yes
USE_RUBY_FEATURES=	optparse strscan
USE_RUBY_SETUP=	yes

RUBY_MODNAME=	rd

DOCS_EN=	README.rd	README.html	doc/rd-draft.rd
DOCS_JA=	README.rd.ja	README.ja.html	doc/rd-draft.rd.ja

post-install:
	${MKDIR} ${RUBY_SITELIBDIR}/rd
	${INSTALL_DATA} ${WRKSRC}/lib/rd/dot.rd2rc ${RUBY_SITELIBDIR}/rd/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/rd/dot.rd2rc ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
