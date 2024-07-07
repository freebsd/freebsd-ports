PORTNAME=	plaso
PORTVERSION=	20231224
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	https://github.com/log2timeline/plaso/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline
WWW=		https://github.com/log2timeline/plaso/wiki

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libcaes>=a:security/libcaes \
		libesedb>=e:devel/libesedb \
		libevt>=a:devel/libevt \
		libevtx>=a:devel/libevtx \
		libfwsi>=e:devel/libfwsi \
		liblnk>=0:devel/liblnk \
		libmsiecf>=a:devel/libmsiecf \
		libolecf>=a:devel/libolecf \
		libregf>=a:devel/libregf \
		libscca>=a:devel/libscca \
		libsigscan>=e:devel/libsigscan \
		${PYTHON_PKGNAMEPREFIX}acstore>=0:devel/py-acstore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}artifacts>=0:security/py-artifacts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bencode.py>=0:converters/py-bencode.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfvfs>=0:security/py-dfvfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfwinreg>=0:security/py-dfwinreg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dtfabric>=0:devel/py-dtfabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flor>=0:textproc/py-flor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opensearch-py>=0:textproc/py-opensearch-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>=0:devel/py-xattr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstd>=0:archivers/py-zstd@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fakeredis>=0:databases/py-fakeredis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist concurrent cryptography distutils
# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LANG=${USE_LOCALE} LC_ALL=${USE_LOCALE} ${TAR}
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} "s|'share', 'artifacts'|'share', '${PYTHON_PKGNAMEPREFIX}artifacts'|" \
		${WRKSRC}/plaso/cli/helpers/artifact_definitions.py
	${REINPLACE_CMD} "s|'share', 'plaso'|'share', '${PYTHON_PKGNAMEPREFIX}plaso'|" \
		${WRKSRC}/plaso/cli/helpers/data_location.py
	${REINPLACE_CMD} "s|share/plaso|${DATADIR_REL}|" \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} "/cffi/d" ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
