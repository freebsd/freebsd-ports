# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	fftw3
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	math ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/ruby-fftw3/release/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/ruby-fftw3/release/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/ruby-fftw3/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	A Ruby interface to the FFTW ver.3

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3
BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DOCS=		LICENSE.txt doc/*

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
