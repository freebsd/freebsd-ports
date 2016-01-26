# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfvfs
PORTVERSION=	20160108
CATEGORIES=	security devel python
MASTER_SITES=	https://github.com/log2timeline/dfvfs/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Virtual File System

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libbde>=a:${PORTSDIR}/devel/libbde \
		libewf>=0:${PORTSDIR}/devel/libewf \
		libfsntfs>=e:${PORTSDIR}/devel/libfsntfs \
		libqcow>=a:${PORTSDIR}/devel/libqcow \
		libsigscan>=e:${PORTSDIR}/devel/libsigscan \
		libsmdev>=a:${PORTSDIR}/devel/libsmdev \
		libsmraw>=a:${PORTSDIR}/devel/libsmraw \
		libvhdi>=e:${PORTSDIR}/devel/libvhdi \
		libvmdk>=e:${PORTSDIR}/devel/libvmdk \
		libvshadow>=0:${PORTSDIR}/devel/libvshadow \
		${PYTHON_PKGNAMEPREFIX}construct>=0:${PORTSDIR}/devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:${PORTSDIR}/sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	distutils autoplist

# Note: for regression tests set LANG to en_US.UTF-8

.include <bsd.port.mk>
