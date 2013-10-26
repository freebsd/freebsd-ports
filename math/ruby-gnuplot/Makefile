# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	math ruby
MASTER_SITES=	SF/r${PORTNAME}/OldFiles
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	r${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A pipe-based interface to the gnuplot package for Ruby

RUN_DEPENDS=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/*.rb

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/gplot

NO_STAGE=	yes
post-patch:
	${RUBY} -i.orig -p \
		-e 'gsub %r:#!/bin/env:, "#!/usr/bin/env"' \
			${WRKSRC}/Gnuplot.rb

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/gplot
	${INSTALL_DATA} ${WRKSRC}/Gnuplot.rb ${RUBY_SITELIBDIR}/gplot/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*_demo.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ChangeLog.txt README
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
