# New ports collection makefile for:    Ruby-html-parser
# Date created:         7 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	html-parser
PORTVERSION=	19990912.p1
CATEGORIES=	textproc	# ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/html-parser/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

NO_BUILD=	yes

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

do-install:
	@cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/html-parser
	${INSTALL_DATA} ${WRKSRC}/README.html ${PREFIX}/share/doc/ruby/html-parser/
.endif

.include <bsd.port.mk>
