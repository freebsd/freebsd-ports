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

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

post-install:
	@${MV} ${PREFIX}/bin/fngrab.py ${PREFIX}/bin/fngrab

.include <bsd.port.mk>
