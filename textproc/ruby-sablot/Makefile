# New ports collection makefile for:	Ruby-sablot
# Date created:		9 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sablot
PORTVERSION=	0.4.0
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.inac.co.jp/~maki/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	sablot.51:${PORTSDIR}/textproc/sablotron

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

INSTALL_TARGET=	site-install

DOCS=		README		sablot.html	sablot.rd

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${RUBY_RD} sablot.rd > sablot.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
