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
COMMENT=	Ruby interface to Amazon's Web Services

DEPRECATED=	Rendered obsolete by upstream since Amazon shut down access to AWS API v3 (2008-03-31). Use www/ruby-aws instead
EXPIRATION_DATE=2015-06-30

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

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.2
BROKEN=		Does not build
.endif

.include <bsd.port.post.mk>
