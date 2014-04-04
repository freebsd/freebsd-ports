# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	fftw3
PORTVERSION=	0.4
PORTREVISION=	3
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

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3
BUILD_DEPENDS=	rubygem-narray>=0:${PORTSDIR}/math/rubygem-narray
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS+=	--with-narray-include=${LOCALBASE}/lib/ruby/gems/${RUBY_VER}/gems/narray-${NARRAY_VERSION}/

DOCS=		LICENSE.txt doc/*

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include "${.CURDIR}/../rubygem-narray/Makefile.version"

.include <bsd.port.mk>
