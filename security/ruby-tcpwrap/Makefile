# New ports collection makefile for:	Ruby-tcpwrap
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tcpwrap
PORTVERSION=	0.3
CATEGORIES=	security ruby
MASTER_SITES=	http://www.shugo.net/archive/ruby-tcpwrap/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
CONFIGURE_ARGS=	--with-libwrap-dir="/usr" \
		--with-ident-dir="${LOCALBASE}"

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
