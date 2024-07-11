PORTNAME=	dfvfs
PORTVERSION=	20231208
PORTREVISION=	1
CATEGORIES=	security devel python
MASTER_SITES=	https://github.com/log2timeline/dfvfs/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Virtual File System
WWW=		https://github.com/log2timeline/dfvfs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libbde>=a:devel/libbde \
		libewf>=0:devel/libewf \
		libfsapfs>=e:devel/libfsapfs \
		libfsext>=e:devel/libfsext \
		libfsfat>=e:devel/libfsfat \
		libfshfs>=e:devel/libfshfs \
		libfsntfs>=e:devel/libfsntfs \
		libfsxfs>=e:devel/libfsxfs \
		libfvde>=0:sysutils/libfvde \
		libfwnt>=e:devel/libfwnt \
		libluksde>=e:devel/libluksde \
		libmodi>=e:devel/libmodi \
		libphdi>=e:devel/libphdi \
		libqcow>=a:devel/libqcow \
		libsigscan>=e:devel/libsigscan \
		libsmdev>=a:devel/libsmdev \
		libsmraw>=a:devel/libsmraw \
		libvhdi>=e:devel/libvhdi \
		libvmdk>=e:devel/libvmdk \
		libvsapm>=e:devel/libvsapm \
		libvsgpt>=e:devel/libvsgpt \
		libvshadow>=0:devel/libvshadow \
		libvslvm>=e:devel/libvslvm \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dtfabric>=0:devel/py-dtfabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>=0:devel/py-xattr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist concurrent cryptography distutils
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

NO_ARCH=	yes

# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

post-patch:
	${REINPLACE_CMD} "/cffi/d" ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
