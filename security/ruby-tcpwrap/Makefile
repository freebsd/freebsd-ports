# New ports collection makefile for:	Ruby-libwrap
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libwrap
PORTVERSION=	0.1
CATEGORIES=	security ruby
MASTER_SITES=	http://www.ruby-lang.org/~shugo/libwrap-ruby/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident
.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}-ruby
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

DOCS_EN=	README.en	doc/en/tcpd.html
DOCS_JA=	README.ja	doc/ja/tcpd.html

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/tcpd
	${INSTALL_DATA} ${WRKSRC}/sample/echod.rb ${PREFIX}/share/examples/ruby/tcpd/
	${MKDIR} ${PREFIX}/share/doc/ruby/tcpd/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/tcpd/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/tcpd/ja/
.endfor
.endif

.include <bsd.port.mk>
