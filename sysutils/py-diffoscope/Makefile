PORTNAME=	diffoscope
PORTVERSION=	301
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	In-depth comparison of files, archives, and directories
WWW=		https://diffoscope.org/ \
		https://salsa.debian.org/reproducible-builds/diffoscope

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	gdiff:textproc/diffutils \
		${PYTHON_PKGNAMEPREFIX}libarchive-c>=0:archivers/py-libarchive-c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0:devel/py-python-magic@${PY_FLAVOR}
TEST_DEPENDS=	isoinfo:sysutils/cdrkit \
		rpm2cpio:archivers/rpm2cpio \
		zipinfo:archivers/unzip

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CPE_VENDOR=	reproducible_builds

.include <bsd.port.mk>
