# New ports collection makefile for: scgi
# Date created:		19 Aug 2002
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scgi
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	http://www.mems-exchange.org/software/files/scgi/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nbm@FreeBSD.org

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
