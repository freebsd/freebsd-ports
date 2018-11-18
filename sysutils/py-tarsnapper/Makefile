# Created by: philip@FreeBSD.org
# $FreeBSD$

PORTNAME=	tarsnapper
PORTVERSION=	0.4
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Tarsnap wrapper which expires backups using a gfs-scheme

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes

GH_ACCOUNT=	miracle2k
GH_PROJECT=	tarsnapper

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>0:textproc/py-pyaml@${PY_FLAVOR} \
		tarsnap>=0:sysutils/tarsnap

.include <bsd.port.mk>
