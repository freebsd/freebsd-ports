# New ports collection makefile for:	Ruby-BigFloat
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bigfloat
PORTVERSION=	1.1.3
CATEGORIES=	math ruby
MASTER_SITES=	http://www.tinyforest.gr.jp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/bigfloat/ja
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/bigfloat_en.html \
		${RUBY_DOCDIR}/bigfloat
	${INSTALL_DATA} ${WRKSRC}/bigfloat.html \
		${RUBY_DOCDIR}/bigfloat/ja
.endif

.include <bsd.port.mk>
