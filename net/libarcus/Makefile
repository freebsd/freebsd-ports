PORTNAME=	libArcus
PORTVERSION=	4.13.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	net cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Communication library between internal components for Ultimaker
WWW=		https://github.com/Ultimaker/libArcus

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Fails to build with modern python
EXPIRATION_DATE=	2024-06-29

BUILD_DEPENDS=	sip:devel/py-sip4
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++17-lang python pyqt:5
USE_PYQT=	pysip
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
USE_LDCONFIG=	yes
#GH_TAGNAME=	3afb644

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD} \
				-DPYTHON_INCLUDEDIR:STRING=${PYTHON_INCLUDEDIR}

.include <bsd.port.mk>
