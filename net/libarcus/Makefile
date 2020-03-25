# $FreeBSD$

PORTNAME=	libArcus
PORTVERSION=	15.06.03
CATEGORIES=	net cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Communication library between internal components for Ultimaker

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sip:devel/py-sip@${PY_FLAVOR}
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
USE_LDCONFIG=	yes
GH_TAGNAME=	d0f1ac1

.include <bsd.port.mk>
