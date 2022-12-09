PORTNAME=	zfs-autobackup
DISTVERSION=	3.1.3
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zfs_autobackup-${DISTVERSION}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Periodicly backup zfs filesystems to other locations
WWW=		https://github.com/psy0rz/zfs_autobackup

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
