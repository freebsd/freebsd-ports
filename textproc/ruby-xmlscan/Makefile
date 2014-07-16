# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xmlscan
PORTVERSION=	0.2.3
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High-performance non-validating XML parser written in 100% pure Ruby

NO_LATEST_LINK=	yes
USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	ChangeLog \
		README \
		THANKS \
		doc/changes.* \
		doc/en/*
DOCS_JA=	doc/ja/*

OPTIONS_DEFINE=	DOCS

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
