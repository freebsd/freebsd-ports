# New ports collection makefile for:	maxima
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	maxima
PORTVERSION=	5.6
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/maxima/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	maxima-5.6
EXTRACT_SUFX=	.tgz

MAINTAINER=	sf@dsinw.com

BUILD_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl
LIB_DEPENDS=	tk83:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	${LOCALBASE}/bin/lisp:${PORTSDIR}/lang/cmucl \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot

USE_XLIB=	yes
NO_BUILD=	yes

do-install:
	-${MKDIR} ${PREFIX}/lib/${DISTNAME}
	(cd ${WRKDIR} && tar fc - ${DISTNAME}) | (cd ${PREFIX}/lib && tar fx -)

post-install:
	(cd ${PREFIX}/lib/${DISTNAME}/src ; \
		${CP} ${FILESDIR}/build.lisp . ; \
		${LOCALBASE}/bin/lisp -eval '(load "build.lisp")' ; \
		${RM} build.lisp *.x86f)
	${SED} -e 's#@MAXIMAPREFIX@#${PREFIX}/lib/${DISTNAME}/#g ; \
		s#@LISPPREFIX@#${LOCALBASE}/bin/#g' \
		${FILESDIR}/maxima.sh >${LOCALBASE}/bin/maxima
	${CHMOD} 755 ${LOCALBASE}/bin/maxima

.include <bsd.port.mk>
