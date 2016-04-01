# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfvfs
PORTVERSION=	20160108
PORTREVISION=	1
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
		libqcow>=a:devel/libqcow \
		libsigscan>=e:devel/libsigscan \
		libsmdev>=a:devel/libsmdev \
		libsmraw>=a:devel/libsmraw \
		libvhdi>=e:devel/libvhdi \
		libvmdk>=e:devel/libvmdk \
		libvshadow>=0:devel/libvshadow \
		${PYTHON_PKGNAMEPREFIX}construct>=0:devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	distutils autoplist

# Note: for regression tests set LANG to en_US.UTF-8

.include <bsd.port.mk>
