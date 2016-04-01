# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytsk
PORTVERSION=	20160111
CATEGORIES=	sysutils security devel python
MASTER_SITES=	https://github.com/py4n6/pytsk/releases/download/${PORTVERSION}${EXTRACT_SUFX}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for the Sleuthkit

LICENSE=	APACHE20

LIB_DEPENDS=	libtsk.so:sysutils/sleuthkit

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		python tar:tgz
USE_PYTHON=	distutils autoplist

post-patch:
	${REINPLACE_CMD} 's|"/", "usr", "local"|"${LOCALBASE}"|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
