# Created by: IWATSUKI Hiroyuki <don@na.rim.or.jp>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	0.8.1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	don@na.rim.or.jp
COMMENT=	A Ruby interface to Amazon Web Services

CONFLICTS=	ruby-amazon-[0-9]*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		COPYING INSTALL NEWS README
EXAMPLES=	example/*

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
