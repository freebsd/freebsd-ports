# New ports collection makefile for:	Ruby-uri
# Date created:		14 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	uri
PORTVERSION=	4.22
CATEGORIES=	net ruby
MASTER_SITES=	http://www02.so-net.ne.jp/%7Egreentea/ruby/uri/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

MODULES=	uri.rb urireg.rb

DOCS=		index.html
EXAMPLES=	in-uri.txt test-uri.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/uri
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/ruby/uri/
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/uri
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/uri/
.endfor
.endif

.include <bsd.port.mk>
