# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	diffoscope
PORTVERSION=	49
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	In-depth comparison of files, archives, and directories

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libarchive-c>=0:archivers/py3-libarchive-c \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0:devel/py3-python-magic
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest \
		zipinfo:archivers/unzip \
		isoinfo:sysutils/cdrkit \
		rpm2cpio:archivers/rpm2cpio

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-extract:
	@${RM} -rf \
		${WRKSRC}/tests/__pycache__ \
		${WRKSRC}/tests/comparators/__pycache__

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test --pytest-args="-rsx -l -vv"

.include <bsd.port.mk>
