# New ports collection makefile for:	pyslsk
# Date created:				2003-01-20
# Whom:					Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pyslsk
PORTVERSION=	1.2.7b
PORTREVISION=	6
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Client for SoulSeek filesharing system

DEPRECATED=	unmantaind upstream, use net-p2p/nicotine-plus
EXPIRATION_DATE=	2010-11-24

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

.if !defined(WITHOUT_BSDDB3)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/bsddb3/__init__.py:${PORTSDIR}/databases/py-bsddb3
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_WX=		2.6
WX_COMPS=	python

.include <bsd.port.mk>
