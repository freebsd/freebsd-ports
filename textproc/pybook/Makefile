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

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,python2,python,g" ${WRKSRC}/pybook.py

post-install:
	@${MV} -f ${PREFIX}/bin/pybook.py ${PREFIX}/bin/pybook

.include <bsd.port.mk>
