# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfvfs
PORTVERSION=	20141028
CATEGORIES=	security devel python
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSZTI3MWV6di1fRDg/ \
		https://github.com/log2timeline/dfvfs/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Virtual File System

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libbde>=a:${PORTSDIR}/devel/libbde \
		libewf>=0:${PORTSDIR}/devel/libewf \
		libqcow>=a:${PORTSDIR}/devel/libqcow \
		libsmdev>=a:${PORTSDIR}/devel/libsmdev \
		libsmraw>=a:${PORTSDIR}/devel/libsmraw \
		libvhdi>=e:${PORTSDIR}/devel/libvhdi \
		libvmdk>=e:${PORTSDIR}/devel/libvmdk \
		libvshadow>=0:${PORTSDIR}/devel/libvshadow \
		${PYTHON_PKGNAMEPREFIX}construct>=0:${PORTSDIR}/devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:${PORTSDIR}/sysutils/py-pytsk

USES=		python:2
USE_PYTHON=	distutils autoplist

PORTDOCS=	ACKNOWLEDGEMENTS AUTHORS

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

# Note: for regression tests set LANG to en_US.UTF-8

.include <bsd.port.mk>
