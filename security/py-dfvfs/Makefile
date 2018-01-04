# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfvfs
PORTVERSION=	20171230
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
		${PYTHON_PKGNAMEPREFIX}construct>=0:devel/py-construct@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyliblzma>=0:archivers/py-pyliblzma@${FLAVOR}
TEST_ENV=	${MAKE_ENV} PYTHONHTTPSVERIFY=0
.else
TEST_DEPENDS+=	ca_root_nss>=0:security/ca_root_nss
.endif

do-test:
	@${TOUCH} ${TEST_WRKSRC}/utils/__init__.py
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.post.mk>
