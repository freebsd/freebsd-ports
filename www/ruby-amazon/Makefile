# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	amazon
PORTVERSION=	0.9.2
CATEGORIES=	www ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby interface to Amazon's Web Services

CONFLICTS=	ruby-aws-[0-9]*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		NEWS README TODO
EXAMPLES=	example/*

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
