# ex:ts=8
# Ports collection makefile for:	py-fngrab
# Date created:			Mar 23, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	fngrab
PORTVERSION=	0.0.4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freebbs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for the official Freenet Project's freenet_request

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${MV} ${PREFIX}/bin/fngrab.py ${PREFIX}/bin/fngrab

.include <bsd.port.mk>
