# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	numru_misc
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	math ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/numru-misc/release/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/numru-misc/release/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/numru-misc/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	numru-misc-${PORTVERSION}
DIST_SUBDIR=	ruby

OPTIONS_DEFINE=	DOCS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Collection of misc functions and classes to facilitate programming

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${RUBY_SITELIBDIR}/narray_miss.rb:${PORTSDIR}/math/ruby-narray_miss

USE_RUBY=	yes
NO_BUILD=	yes

DOCS=		ChangeLog LICENSE.txt doc/*

DEPRECATED=	Depends on deprecated math/ruby-narray
EXPIRATION_DATE=	2014-09-20

do-install:
	@cd ${WRKSRC}/ && ${RUBY} ./install.rb -d ${STAGEDIR}${RUBY_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.0
BROKEN=		Does not build with Ruby 2.0 or newer
.endif

.include <bsd.port.post.mk>
