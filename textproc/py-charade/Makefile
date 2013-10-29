# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	charade
PORTVERSION=	1.0.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Universal encoding detector for python 2 and 3

LICENSE=	LGPL3

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} 's/="LGPL",/="LGPL", zip_safe=False,/' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
