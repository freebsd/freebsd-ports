# ex:ts=8
# New ports collection makefile for:	forg
# Date created:			Sep 25, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	forg
PORTVERSION=	0.5.1
CATEGORIES=	net python
MASTER_SITES=	http://opop.nols.com/proggie/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS= 	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/pmw

USE_REINPLACE=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

post-patch:
.for file in forg.py mini-forg.py
	@${REINPLACE_CMD} -e "s,/usr/bin/python,${PYTHON_CMD},g" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/forg.py ${PREFIX}/bin/forg
	${CP} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
