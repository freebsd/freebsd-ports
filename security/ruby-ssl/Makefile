# New ports collection makefile for:	Ruby-ssl
# Date created:		9 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ssl
PORTVERSION=	0.3.2
CATEGORIES=	security ruby
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_OPENSSL=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-openssl-include="${OPENSSLBASE}/include/openssl" \
		--with-openssl-lib="${OPENSSLBASE}/lib"
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog doc/ssl.html doc/ssl.rd
DOCS_JA=	doc/ssl.ja.html doc/ssl.ja.rd

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; \
	${RUBY_RD} doc/ssl.rd > doc/ssl.html; \
	${RUBY_RD} doc/ssl.ja.rd > doc/ssl.ja.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
