# New ports collection makefile for:	GPhys
# Date created:		14 March 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gphys
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	science ruby
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/ruby/products/gphys/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	murakami@ahs.scitec.kobe-u.ac.jp
COMMENT=	A multi-purpose class to handle gridded physical quantities

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${RUBY_SITELIBDIR}/narray_miss.rb:${PORTSDIR}/math/ruby-narray_miss \
		${RUBY_SITEARCHLIBDIR}/numru/dcl_raw.so:${PORTSDIR}/science/ruby-dcl \
		${RUBY_SITEARCHLIBDIR}/numru/netcdfraw.so:${PORTSDIR}/math/ruby-netcdf \
		${RUBY_SITEARCHLIBDIR}/numru/fftw3.so:${PORTSDIR}/math/ruby-fftw3 \
		${RUBY_SITELIBDIR}/numru/misc.rb:${PORTSDIR}/math/ruby-numru_misc \
		${RUBY_SITELIBDIR}/numru/units.rb:${PORTSDIR}/math/ruby-numru_units

USE_RUBY=	yes
NO_BUILD=	yes

DOCS=		ChangeLog README TODO_ep_flux doc/*.html
DOCS_DR=	doc/derivative/*.html doc/derivative/math-doc/document.pdf
DOCS_EP=	doc/ep_flux/*.html doc/ep_flux/math-doc/document.pdf

do-install:
	@cd ${WRKSRC}/ && ${RUBY} ./install.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/test
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/testdata
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/sample
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/sample/ep_flux
	${INSTALL_DATA} ${WRKSRC}/test/* ${RUBY_MODEXAMPLESDIR}/test
	${INSTALL_DATA} ${WRKSRC}/testdata/* ${RUBY_MODEXAMPLESDIR}/testdata
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/sample
	${INSTALL_DATA} ${WRKSRC}/sample/ep_flux/* ${RUBY_MODEXAMPLESDIR}/sample/ep_flux
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODDOCDIR}/derivative
	${MKDIR} ${RUBY_MODDOCDIR}/ep_flux
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.for f in ${DOCS_DR}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/derivative
.endfor
.for f in ${DOCS_EP}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ep_flux
.endfor
.endif

.include <bsd.port.mk>
