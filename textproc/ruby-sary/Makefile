# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sary
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://sary.sourceforge.net/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Ruby interface to the Sary library

LIB_DEPENDS=	libsary.so:${PORTSDIR}/textproc/sary

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USES=		pkgconfig

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	*.en.rd *.ja.rd

DOCS_EN=	ChangeLog \
		${RUBY_RD_FILES:M*.en.rd} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.ja.rd} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rsary.rb ${STAGEDIR}${PREFIX}/bin/
	${MKDIR}  ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.mk>
