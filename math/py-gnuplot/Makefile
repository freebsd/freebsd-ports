# New ports collection makefile for:	py-gnuplot
# Date created:				3 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-gnuplot
PORTVERSION=	1.5
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnuplot-py
DISTNAME=	Gnuplot-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/_numpy.so:${PORTSDIR}/math/numpy
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		${PYTHON_SITELIBDIR}/Numeric/_numpy.so:${PORTSDIR}/math/numpy

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC}; ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/py-gnuplot
	cd ${WRKSRC}/doc && ${TAR} -chf - * | \
		${TAR} --unlink -xf - -C ${PREFIX}/share/doc/py-gnuplot
.endif

.include <bsd.port.mk>
