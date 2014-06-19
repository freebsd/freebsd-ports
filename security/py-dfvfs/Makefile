# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfvfs
PORTVERSION=	20140604
CATEGORIES=	security devel python
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSZTI3MWV6di1fRDg/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Virtual File System

LICENSE=	APACHE20

RUN_DEPENDS=	libewf>=0:${PORTSDIR}/devel/libewf \
		libqcow>=a:${PORTSDIR}/devel/libqcow \
		libsmdev>=a:${PORTSDIR}/devel/libsmdev \
		libvhdi>=e:${PORTSDIR}/devel/libvhdi \
		libvmdk>=e:${PORTSDIR}/devel/libvmdk \
		libvshadow>=0:${PORTSDIR}/devel/libvshadow \
		${PYTHON_PKGNAMEPREFIX}construct>=0:${PORTSDIR}/devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:${PORTSDIR}/sysutils/py-pytsk

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	ACKNOWLEDGEMENTS AUTHORS

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
