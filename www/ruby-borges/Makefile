# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	borges
PORTVERSION=	1.1.0
CATEGORIES=	www ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A web application framework for Ruby that allows linear programming

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		BUGS CHANGELOG README
EXAMPLES=	data/examples/ruby/borges/*

post-extract:
# This port is not really RUBY_MODEXAMPLESDIR/RUBY_MODDOCDIR clean
.for d in doc examples
	${MV} ${WRKSRC}/data/${d}/ruby/Borges ${WRKSRC}/data/${d}/ruby/borges
	${MV} ${WRKSRC}/data/${d}/ruby ${WRKSRC}/data/${d}/${RUBY_NAME}
.endfor

.include <bsd.port.mk>
