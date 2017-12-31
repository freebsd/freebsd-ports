# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
PORTVERSION=	20171231
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
		${PYTHON_PKGNAMEPREFIX}artifacts>=0:security/py-artifacts@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bencode.py>=0:converters/py-bencode.py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}binplist>=0:devel/py-binplist@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}construct>=0:devel/py-construct@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfvfs>=0:security/py-dfvfs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfwinreg>=0:security/py-dfwinreg@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:net/py-dpkt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}efilter>=0:devel/py-efilter@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	hachoir-core>=0:devel/hachoir-core \
		hachoir-metadata>=0:sysutils/hachoir-metadata \
		hachoir-parser>=0:devel/hachoir-parser \
		${PYTHON_PKGNAMEPREFIX}pyliblzma>=0:archivers/py-pyliblzma@${FLAVOR}
TEST_ENV=	${MAKE_ENV} PYTHONHTTPSVERIFY=0
.else
TEST_DEPENDS+=	ca_root_nss>=0:security/ca_root_nss
.endif

do-test:
	@${TOUCH} ${TEST_WRKSRC}/utils/__init__.py
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.post.mk>
