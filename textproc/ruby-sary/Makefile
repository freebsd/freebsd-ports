# New ports collection makefile for:	Ruby/Sary
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sary
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://prime.sourceforge.jp/freebsd/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to the Sary library

LIB_DEPENDS=	sary.9:${PORTSDIR}/textproc/sary

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_WITH_PTHREAD=	yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	*.en.rd *.ja.rd

DOCS_EN=	ChangeLog \
		${RUBY_RD_FILES:M*.en.rd} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.ja.rd} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

post-install: doc-install
	${INSTALL_SCRIPT} ${WRKSRC}/rsary.rb ${PREFIX}/bin/

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
