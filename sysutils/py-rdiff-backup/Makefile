PORTNAME=	rdiff-backup
DISTVERSION=	2.2.5
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Easy to use and efficient backup and restore utility
WWW=		https://rdiff-backup.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		rubygem-asciidoctor>0:textproc/rubygem-asciidoctor
LIB_DEPENDS=	librsync.so:net/librsync
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		localbase:ldflags python
USE_LDCONFIG=	yes
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS=	rdiff-backup-devel rdiff-backup-1.0*

PORTSCOUT=	limitw:1,even

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rdiff_backup/_librsync*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rdiff_backup/C*.so

.include <bsd.port.mk>
