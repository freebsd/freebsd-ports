# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfvfs
PORTVERSION=	20160918
CATEGORIES=	security devel python
MASTER_SITES=	https://github.com/log2timeline/dfvfs/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Virtual File System

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libbde>=a:devel/libbde \
		libewf>=0:devel/libewf \
		libfsntfs>=e:devel/libfsntfs \
		libfvde>=0:sysutils/libfvde \
		libfwnt>=e:devel/libfwnt \
		libqcow>=a:devel/libqcow \
		libsigscan>=e:devel/libsigscan \
		libsmdev>=a:devel/libsmdev \
		libsmraw>=a:devel/libsmraw \
		libvhdi>=e:devel/libvhdi \
		libvmdk>=e:devel/libvmdk \
		libvshadow>=0:devel/libvshadow \
		libvslvm>=e:devel/libvslvm \
		${PYTHON_PKGNAMEPREFIX}pyliblzma>=0:archivers/py-pyliblzma \
		${PYTHON_PKGNAMEPREFIX}construct>=0:devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3

NO_ARCH=	yes
USES=		python:2.7
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils autoplist
TEST_ENV=	${MAKE_ENV} PYTHONHTTPSVERIFY=0

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.mk>
