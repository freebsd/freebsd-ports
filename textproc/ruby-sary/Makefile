# New ports collection makefile for:	Ruby/Sary
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sary
PORTVERSION=	0.4
CATEGORIES=	textproc ruby
MASTER_SITES=	ftp://ftp.namazu.org/sary/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	sary.8:${PORTSDIR}/textproc/sary

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDTOOL=	yes

RUBY_WITH_PTHREAD=	yes

INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog *.en.*
DOCS_JA=	*.ja.*

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; for f in *.rd; do \
		${RUBY_RD2} $$f > $${f%.rd}.html; \
	done
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rsary.rb ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
