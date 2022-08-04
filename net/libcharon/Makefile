PORTNAME=	libCharon
# XXX there is no 4.13.1
# https://github.com/Ultimaker/libCharon/tags
DISTVERSION=	4.13.0
CATEGORIES=	net devel cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	File metadata and streaming library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake python:3.4+
STRIP=

USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD} \
		-DPYTHONPREFIX_SITELIBDIR:STRING=${PYTHONPREFIX_SITELIBDIR}
NO_ARCH=	yes

.include <bsd.port.mk>
