# New ports collection makefile for:	Ruby-tcpwrap
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tcpwrap
PORTVERSION=	0.2
CATEGORIES=	security ruby
MASTER_SITES=	http://www.shugo.net/archive/ruby-tcpwrap/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident
.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
CONFIGURE_ARGS=	--with-ident-dir="${LOCALBASE}"
.if !exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--with-libwrap-dir="/usr"
.else
CONFIGURE_ARGS+=	--with-libwrap-dir="${LOCALBASE}"
.endif
INSTALL_TARGET=	site-install

DOCS_EN=	README.en	doc/tcpwrap.html.en
DOCS_JA=	README.ja	doc/tcpwrap.html.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/tcpwrap
	${INSTALL_DATA} ${WRKSRC}/sample/echod.rb ${RUBY_EXAMPLESDIR}/tcpwrap/
	${MKDIR} ${RUBY_DOCDIR}/tcpwrap/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/tcpwrap/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/tcpwrap/ja/
.endfor
.endif

.include <bsd.port.mk>
