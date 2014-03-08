# Created by: ijliao
# $FreeBSD$

PORTNAME=	forg
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	http://gopher.quux.org:70/give-me-gopher/
# Old home website doesn't seem to work anymore (19/05/03)
#MASTER_SITES=	http://opop.nols.com/proggie/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Gopher client

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USE_PYTHON=	yes
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
.for file in forg.py mini-forg.py
	@${REINPLACE_CMD} -e "s,/usr/bin/python,${PYTHON_CMD},g" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/forg.py ${PREFIX}/bin/forg
	${CP} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
