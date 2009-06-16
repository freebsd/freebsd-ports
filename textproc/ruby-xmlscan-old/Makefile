# New ports collection makefile for:	ruby-xmlscan
# Date created:		7 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlscan
PORTVERSION=	0.0.10
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/old/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure Ruby XML/HTML scanner and XPath processor/compiler modules

BUILD_DEPENDS=	racc:${PORTSDIR}/devel/ruby-racc

USE_RUBY=	yes
USE_RUBY_FEATURES=	racc-runtime

do-build:
	cd ${WRKSRC}; racc -v -g -c -o xmldtd.rb xmldtd.ry

do-install:
	cd ${WRKSRC}; ${INSTALL_DATA} [hx]*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
