# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	google
PORTVERSION=	0.6.0
CATEGORIES=	www databases ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby interface to Google's SOAP-driven Web API

USE_RUBY=	yes
USE_RUBY_FEATURES=	soap
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		CHANGES Changelog README google.html
EXAMPLES=	examples/*

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
