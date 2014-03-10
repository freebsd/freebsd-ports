# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	gphys
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	science ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/gphys/release/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/gphys/release/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/gphys/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	A multi-purpose class to handle gridded physical quantities

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${RUBY_SITELIBDIR}/narray_miss.rb:${PORTSDIR}/math/ruby-narray_miss \
		${RUBY_SITEARCHLIBDIR}/numru/dcl_raw.so:${PORTSDIR}/science/ruby-dcl \
		${RUBY_SITEARCHLIBDIR}/numru/netcdfraw.so:${PORTSDIR}/science/ruby-netcdf \
		${RUBY_SITEARCHLIBDIR}/numru/fftw3.so:${PORTSDIR}/math/ruby-fftw3 \
		${RUBY_SITELIBDIR}/numru/misc.rb:${PORTSDIR}/math/ruby-numru_misc \
		${RUBY_SITELIBDIR}/numru/units.rb:${PORTSDIR}/math/ruby-numru_units \
		${RUBY_SITEARCHLIBDIR}/rb_gsl.so:${PORTSDIR}/math/ruby-gsl
BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
DOCSDIR=	${RUBY_MODDOCDIR}
PORTEXAMPLES=	sample* test*
PORTDOCS=	ChangeLog LICENSE.txt README TODO_ep_flux doc*

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && ${MAKE} install
	cd ${WRKSRC} && ${RUBY} install.rb

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for i in ${PORTEXAMPLES}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${i}" ${EXAMPLESDIR})
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${i}" ${DOCSDIR})
.endfor
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
