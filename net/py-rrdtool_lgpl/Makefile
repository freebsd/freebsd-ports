# Ports collection makefile for:	py-rrdtool_lgpl
# Date created:			8 January 2003
# Whom:	      			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	rrdtool_lgpl
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py-rrdtool
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-rrdtool-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to RRDTool, the graphing and logging utility

LIB_DEPENDS=	rrd:${PORTSDIR}/net/rrdtool

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

LIBDIR?=	${LOCALBASE}/lib # directory where librrd.so lives

.include <bsd.port.mk>
