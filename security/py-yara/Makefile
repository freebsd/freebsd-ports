# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	2.0.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Python bindings for yara

USE_GITHUB=	yes
GH_ACCOUNT=	plusvic
GH_TAGNAME=	v2.0.0
GH_COMMIT=	d5dbefb

LIB_DEPENDS=	libyara.so:${PORTSDIR}/security/yara

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

BUILD_WRKSRC=	${WRKSRC}/yara-python
INSTALL_WRKSRC=	${WRKSRC}/yara-python

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${BUILD_WRKSRC}/setup.py

.include <bsd.port.mk>
