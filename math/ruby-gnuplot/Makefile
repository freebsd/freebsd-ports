# New ports collection makefile for:	Ruby/Gnuplot
# Date created:		1 Feb 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnuplot
PORTVERSION=	0.2
CATEGORIES=	math ruby
MASTER_SITES=	http://physci.gmu.edu/~gmiller/gnuplot/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/*.rb

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/gplot

post-patch:
	${RUBY} -i.orig -p \
		-e 'gsub %r:/usr/bin/gnuplot:, "${LOCALBASE}/bin/gnuplot"' \
			${WRKSRC}/*.rb

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/gplot
	${INSTALL_DATA} ${WRKSRC}/*.rb ${RUBY_SITELIBDIR}/gplot/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
