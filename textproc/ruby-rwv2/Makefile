# New ports collection makefile for:	RwV2
# Date created:		29 September 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rwv2
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://download.ywesee.com/ruby/rwv2/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension that wraps around wv2

LIB_DEPENDS=	wv2.1:${PORTSDIR}/textproc/wv2

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

CONFIGURE_ARGS=	-- \
		--with-wv2-include="${LOCALBASE}/include/wv2" \
		--with-wv2-lib="${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.8
IGNORE=		only works with ruby 1.8 or later
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.post.mk>
