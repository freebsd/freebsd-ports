# ex:ts=8
# Ports collection makefile for:	pybook
# Date created:			Jan 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pybook
PORTVERSION=	0.6f
CATEGORIES=	textproc python
MASTER_SITES=	http://silmarill.org/pybook/

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

post-patch:
	@${PERL} -pi -e "s,python2,python,g" ${WRKSRC}/pybook.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install
	@${MV} -f ${PREFIX}/bin/pybook.py ${PREFIX}/bin/pybook

.include <bsd.port.mk>
