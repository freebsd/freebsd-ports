# New ports collection makefile for:	pyslsk
# Date created:				2003-01-20
# Whom:					Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pyslsk
PORTVERSION=	0.4.11
CATEGORIES=	net
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/ \
		http://stud4.tuwien.ac.at/~e0125637/

MAINTAINER=	shoesoft@gmx.net
COMMENT=	"Client for SoulSeek filesharing system"

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
