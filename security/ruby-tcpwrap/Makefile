# New ports collection makefile for:	Ruby-tcpwrap
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tcpwrap
PORTVERSION=	0.1
CATEGORIES=	security ruby
MASTER_SITES=	http://www.ruby-lang.org/~shugo/ruby-tcpwrap/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident
.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-ident-dir="${LOCALBASE}"
.if !exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--with-libwrap-dir="/usr"
.else
CONFIGURE_ARGS+=	--with-libwrap-dir="${LOCALBASE}"
.endif

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

DOCS_EN=	README.en	doc/tcpwrap.html.en
DOCS_JA=	README.ja	doc/tcpwrap.html.ja

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/tcpwrap
	${INSTALL_DATA} ${WRKSRC}/sample/echod.rb ${PREFIX}/share/examples/ruby/tcpwrap/
	${MKDIR} ${PREFIX}/share/doc/ruby/tcpwrap/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/tcpwrap/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/tcpwrap/ja/
.endfor
.endif

.include <bsd.port.mk>
