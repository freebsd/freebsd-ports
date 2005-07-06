# New ports collection makefile for:	pyslsk
# Date created:				2003-01-20
# Whom:					Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pyslsk
PORTVERSION=	1.2.7b
CATEGORIES=	net
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Client for SoulSeek filesharing system

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/wx-2.6-gtk2-ansi/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wx-2.6-gtk2-ansi/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

.if !defined(WITHOUT_BSDDB3)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/bsddb3/__init__.py:${PORTSDIR}/databases/py-bsddb3
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

pre-install:
.if exists(${PYTHON_SITELIBDIR}/wx/__init__.py)
BROKEN=	"pyslsk only works with py-wxPython >= 2.6, please deinstall old version first"
.endif

.include <bsd.port.post.mk>
