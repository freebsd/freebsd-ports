# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	math ruby
MASTER_SITES=	SF/r${PORTNAME}/OldFiles
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	r${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pipe-based interface to the gnuplot package for Ruby

RUN_DEPENDS=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/*.rb

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/gplot

DOCSDIR=	${RUBY_MODDOCDIR}
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
PORTDOCS=	*
PORTEXAMPLES=	*

DEPRECATED=	Depends on deprecated math/ruby-narray
EXPIRATION_DATE=	2014-09-20

MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

post-patch:
	${RUBY} -i.orig -p \
		-e 'gsub %r:#!/bin/env:, "#!/usr/bin/env"' \
			${WRKSRC}/Gnuplot.rb

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/gplot
	${INSTALL_DATA} ${WRKSRC}/Gnuplot.rb ${STAGEDIR}${RUBY_SITELIBDIR}/gplot/
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*_demo.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ChangeLog.txt README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
