# Created by: Yarodin <yarodin@gmail.com>
# $FreeBSD$

PORTNAME=	pwman3
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://pwman.bleurgh.com/~ivan/pwman3/source/ \
		http://source.antisupport.com/pwman3/
DISTNAME=	Pwman3-${PORTVERSION}

MAINTAINER=	yarodin@gmail.com
COMMENT=	Console password management application with sql storage

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.0:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent optsuffix

.include <bsd.port.mk>
