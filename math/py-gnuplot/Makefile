# New ports collection makefile for:	py-gnuplot
# Date created:				3 July 2000
# Whom:			Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-gnuplot
PORTVERSION=	1.4
CATEGORIES=	math python
MASTER_SITES=	http://monsoon.harvard.edu/~mhagger/Gnuplot/
DISTNAME=	Gnuplot-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		gnuplot:${PORTSDIR}/math/gnuplot \
		${LOCALBASE}/lib/python1.5/site-packages/Numeric/_numpy.so:${PORTSDIR}/math/numpy

do-build:
	@${LOCALBASE}/bin/python \
		${LOCALBASE}/lib/python1.5/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/lib/python1.5/site-packages/Gnuplot
	${INSTALL_DATA} ${WRKSRC}/*.py? \
		${PREFIX}/lib/python1.5/site-packages/Gnuplot

.include <bsd.port.mk>
