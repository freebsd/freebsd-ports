# ex:ts=8
# Ports collection makefile for:	py-rrdtool
# Date created:			May 31, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	rrdtool
PORTVERSION=	0.1
CATEGORIES=	net python
MASTER_SITES=	http://projects.gasperino.org/projects/PyRRDtool/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyRRDtool-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Python C extension module to access RRDtool files

LIB_DEPENDS=	rrd:${PORTSDIR}/net/rrdtool

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/PyRRDtool/src

do-configure:
	@(cd ${WRKSRC} ; ${MAKE} -f Makefile.pre.in boot)

.include <bsd.port.mk>
