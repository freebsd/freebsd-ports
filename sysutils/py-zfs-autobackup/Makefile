PORTNAME=	zfs-autobackup
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Periodicly backup zfs filesystems to other locations
WWW=		https://github.com/psy0rz/zfs_autobackup

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	psy0rz
GH_PROJECT=	zfs_autobackup

NO_ARCH=	yes

.include <bsd.port.mk>
