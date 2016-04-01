# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sary
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	textproc ruby
MASTER_SITES=	http://sary.sourceforge.net/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the Sary library

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libsary.so:textproc/sary

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

OPTIONS_DEFINE=	DOCS

INSTALL_TARGET=	site-install
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USES=		pkgconfig

RUBY_RD_FILES=	*.en.rd *.ja.rd

DOCS_EN=	ChangeLog \
		${RUBY_RD_FILES:M*.en.rd} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.ja.rd} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

post-install:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR:C/^${LOCALBASE}/${PREFIX}/}/sary.so
	${INSTALL_SCRIPT} ${WRKSRC}/rsary.rb ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_EN} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_JA} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
