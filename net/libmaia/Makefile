PORTNAME=	libmaia
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	5
CATEGORIES=	net

MAINTAINER=	kde@FreeBSD.org
COMMENT=	XML-RPC library for Qt
WWW=		https://github.com/wiedi/libmaia

DEPRECATED=     Depends on unsupported Qt 5, no consumers left
EXPIRATION_DATE=        2026-11-30

USES=		compiler:c++11-lang gmake qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	wiedi
USE_QT=		buildtools:build network xml

PLIST_FILES=	include/maia/maiaObject.h \
		include/maia/maiaXmlRpcClient.h \
		include/maia/maiaXmlRpcServer.h \
		lib/libmaia.a

post-install:
	${INSTALL_DATA} ${WRKSRC}/maiaObject.h \
		${STAGEDIR}${PREFIX}/include/maia

.include <bsd.port.mk>
