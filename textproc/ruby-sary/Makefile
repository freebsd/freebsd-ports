# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sary
PORTVERSION=	1.2.0
PORTREVISION=	4
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

DOCS=	ChangeLog  *.en.rd *.ja.rd

post-install:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR:C/^${LOCALBASE}/${PREFIX}/}/sary.so
	${INSTALL_SCRIPT} ${WRKSRC}/rsary.rb ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
