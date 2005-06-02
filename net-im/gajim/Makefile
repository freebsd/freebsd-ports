# New ports collection makefile for:	gajim
# Date created:				27 April 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.gajim.org/downloads/

MAINTAINER=	vsevolod@highsecure.ru
COMMENT=	Gajim is a Jabber client based on a plugin system

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_X_PREFIX=	yes
USE_PYTHON=	2.3+
USE_GMAKE=	yes
USE_BZIP2=	yes

MAKE_ENV+=	PY_CFLAGS=-I${PYTHON_INCLUDEDIR} \
		PY_PREFIX=${LOCALBASE}

MAN1=		gajim.1

.include <bsd.port.mk>
