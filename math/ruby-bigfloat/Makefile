# New ports collection makefile for:	Ruby-BigFloat
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bigfloat
PORTVERSION= 	1.1.3
CATEGORIES=	math	# ruby
MASTER_SITES=	http://www.tinyforest.gr.jp/ruby/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install

NO_WRKSUBDIR=	yes
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/bigfloat/ja
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/bigfloat_en.html \
		${PREFIX}/share/doc/ruby/bigfloat
	${INSTALL_DATA} ${WRKSRC}/bigfloat.html \
		${PREFIX}/share/doc/ruby/bigfloat/ja
.endif

.include <bsd.port.mk>
