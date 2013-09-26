# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xmlscan
PORTVERSION=	0.0.10
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/old/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure Ruby XML/HTML scanner and XPath processor/compiler modules

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

BUILD_DEPENDS=	racc:${PORTSDIR}/devel/ruby-racc

USE_RUBY=	yes
USE_RUBY_FEATURES=	racc-runtime

NO_STAGE=	yes
do-build:
	cd ${WRKSRC}; racc -v -g -c -o xmldtd.rb xmldtd.ry

do-install:
	cd ${WRKSRC}; ${INSTALL_DATA} [hx]*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
