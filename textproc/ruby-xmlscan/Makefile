# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xmlscan
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High-performance non-validating XML parser written in 100% pure Ruby

USE_RUBY=	yes

NO_ARCH=	yes
NO_BUILD=	yes
USES=		shebangfix
SHEBANG_FILES=	samples/xmlbench.rb \
		samples/xmlconftest.rb

DOCS_EN=	ChangeLog \
		README \
		THANKS \
		doc/changes.* \
		doc/en/*
DOCS_JA=	doc/ja/*

OPTIONS_DEFINE=	DOCS

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${CP} -R ${WRKSRC}/lib/xmlscan ${STAGEDIR}${RUBY_SITELIBDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.mk>
