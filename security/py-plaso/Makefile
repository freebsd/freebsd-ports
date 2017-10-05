# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
PORTVERSION=	20170930
CATEGORIES=	security python
MASTER_SITES=	https://github.com/log2timeline/plaso/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	hachoir-core>=0:devel/hachoir-core \
		hachoir-metadata>=0:sysutils/hachoir-metadata \
		hachoir-parser>=0:devel/hachoir-parser \
		libesedb>=e:devel/libesedb \
		libevt>=a:devel/libevt \
		libevtx>=a:devel/libevtx \
		libfwsi>=e:devel/libfwsi \
		liblnk>=0:devel/liblnk \
		libmsiecf>=a:devel/libmsiecf \
		libolecf>=a:devel/libolecf \
		libregf>=a:devel/libregf \
		libscca>=a:devel/libscca \
		${PYTHON_PKGNAMEPREFIX}artifacts>=0:security/py-artifacts \
		${PYTHON_PKGNAMEPREFIX}bencode>=0:converters/py-bencode \
		${PYTHON_PKGNAMEPREFIX}binplist>=0:devel/py-binplist \
		${PYTHON_PKGNAMEPREFIX}construct>=0:devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime \
		${PYTHON_PKGNAMEPREFIX}dfvfs>=0:security/py-dfvfs \
		${PYTHON_PKGNAMEPREFIX}dfwinreg>=0:security/py-dfwinreg \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:net/py-dpkt \
		${PYTHON_PKGNAMEPREFIX}efilter>=0:devel/py-efilter \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock

NO_ARCH=	yes
USES=		python:2.7
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils autoplist
TEST_ENV=	${MAKE_ENV} PYTHONHTTPSVERIFY=0

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyliblzma>=0:archivers/py-pyliblzma
.endif

do-test:
	@${TOUCH} ${TEST_WRKSRC}/utils/__init__.py
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.post.mk>
