# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmaia
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	kde@FreeBSD.org
COMMENT=	XML-RPC lib for Qt

USES=		gmake qmake
USE_GITHUB=	yes
GH_ACCOUNT=	wiedi
USE_QT5=	buildtools_build network xml

PLIST_FILES=	include/maia/maiaObject.h \
		include/maia/maiaXmlRpcClient.h \
		include/maia/maiaXmlRpcServer.h \
		lib/libmaia.a

post-install:
	${INSTALL_DATA} ${WRKSRC}/maiaObject.h \
		${STAGEDIR}${PREFIX}/include/maia

.include <bsd.port.mk>
