# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	3.3.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Python bindings for yara

USE_GITHUB=	yes
GH_ACCOUNT=	plusvic
GH_TAGNAME=	v3.3.0
GH_COMMIT=	85e913e

LIB_DEPENDS=	libyara.so:${PORTSDIR}/security/yara

USES=		python
USE_PYTHON=	distutils autoplist

BUILD_WRKSRC=	${WRKSRC}/yara-python
INSTALL_WRKSRC=	${WRKSRC}/yara-python

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${BUILD_WRKSRC}/setup.py

.include <bsd.port.mk>
