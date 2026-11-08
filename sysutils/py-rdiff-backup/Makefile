PORTNAME=	rdiff-backup
DISTVERSION=	2.2.7
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rdiff_backup-${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Easy to use and efficient backup and restore utility
WWW=		https://rdiff-backup.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
			rubygem-asciidoctor>0:textproc/rubygem-asciidoctor
BUILD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=		librsync.so:net/librsync

USES=		localbase:ldflags python
USE_LDCONFIG=	yes
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ARGS=	${WRKSRC}/testing/*_test.py
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

CONFLICTS=	rdiff-backup-devel rdiff-backup-1.0*

PORTSCOUT=	limitw:1,even

TEST_WRKSRC=	${STAGEDIR}${PYTHON_SITELIBDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rdiff_backup/_librsync*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rdiff_backup/C*.so

.include <bsd.port.mk>
