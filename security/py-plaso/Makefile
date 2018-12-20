# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
PORTVERSION=	20181219
CATEGORIES=	security python
MASTER_SITES=	https://github.com/log2timeline/plaso/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libesedb>=e:devel/libesedb \
		libevt>=a:devel/libevt \
		libevtx>=a:devel/libevtx \
		libfwsi>=e:devel/libfwsi \
		liblnk>=0:devel/liblnk \
		libmsiecf>=a:devel/libmsiecf \
		libolecf>=a:devel/libolecf \
		libregf>=a:devel/libregf \
		libscca>=a:devel/libscca \
		${PYTHON_PKGNAMEPREFIX}artifacts>=0:security/py-artifacts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bencode.py>=0:converters/py-bencode.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biplist>=0:devel/py-biplist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfvfs>=0:security/py-dfvfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfwinreg>=0:security/py-dfwinreg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}efilter>=0:devel/py-efilter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch>=0:textproc/py-elasticsearch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lz4>=0:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	hachoir-core>=0:devel/hachoir-core@${PY_FLAVOR} \
		hachoir-metadata>=0:sysutils/hachoir-metadata@${PY_FLAVOR} \
		hachoir-parser>=0:devel/hachoir-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backports.lzma>=0:archivers/py-backports.lzma@${PY_FLAVOR}
TEST_ENV=	${MAKE_ENV} PYTHONHTTPSVERIFY=0
.else
TEST_DEPENDS+=	ca_root_nss>=0:security/ca_root_nss
.endif

post-patch:
	${REINPLACE_CMD} "/elasticsearch5/d" ${WRKSRC}/plaso/dependencies.py
	${REINPLACE_CMD} "/^\[elasticsearch5/,/^$$/d" ${WRKSRC}/dependencies.ini
	${REINPLACE_CMD} "s|'share', 'artifacts'|'share', '${PYTHON_PKGNAMEPREFIX}artifacts'|" \
		${WRKSRC}/plaso/cli/helpers/artifact_definitions.py

do-test:
	@${TOUCH} ${TEST_WRKSRC}/utils/__init__.py
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.post.mk>
