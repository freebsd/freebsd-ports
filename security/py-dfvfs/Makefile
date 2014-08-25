# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfvfs
PORTVERSION=	20140824
CATEGORIES=	security devel python
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSZTI3MWV6di1fRDg/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Virtual File System

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

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

.include <bsd.port.mk>
