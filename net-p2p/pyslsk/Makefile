# New ports collection makefile for:	pyslsk
# Date created:				2003-01-20
# Whom:					Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pyslsk
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	shoesoft@gmx.net
COMMENT=	"Client for SoulSeek filesharing system"

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

.if !defined(WITHOUT_BSDDB3)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/bsddb3/__init__.py:${PORTSDIR}/databases/py-bsddb3
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
