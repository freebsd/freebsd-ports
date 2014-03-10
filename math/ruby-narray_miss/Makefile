# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	narray_miss
PORTVERSION=	1.2.8
PORTREVISION=	2
CATEGORIES=	math ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/narray_miss/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/narray_miss/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/narray_miss/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Additional class with processing of missing value to NArray

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/${PORTNAME}/LICENSE.txt

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_RUBY=	yes
USE_RAKE=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DOCS=		LICENSE.txt README.rdoc

NO_STAGE=	yes
do-install:
	cd ${WRKSRC}/${PORTNAME} && ${RAKE_BIN} nongeminstall
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} ${RUBY_MODDOCDIR}
.endfor
.endif

.include <bsd.port.mk>
