# Ports collection makefile for:	py-rrdtool_lgpl
# Date created:			8 January 2003
# Whom:	      			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	rrdtool_lgpl
PORTVERSION=	0.2
CATEGORIES=	net python
MASTER_SITES=	http://savannah.nongnu.org/download/py-rrdtool/py-rrdtool.pkg/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-rrdtool-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	rrd:${PORTSDIR}/net/rrdtool

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

LIBDIR?=	${LOCALBASE}/lib # directory where librrd.so lives

.include <bsd.port.mk>
