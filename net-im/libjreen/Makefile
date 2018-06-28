# $FreeBSD$

PORTNAME=	libjreen
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	akuz84@gmail.com
COMMENT=	Qt4 based jabber library

LICENSE=	GPLv2

LIB_DEPENDS=	libqca.so:devel/qca@qt4 \
		libspeex.so:audio/speex

GH_ACCOUNT=	euroelessar
GH_PROJECT=	jreen

LDFLAGS+=	-L${LOCALBASE}/lib

USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		moc_build qmake_build rcc_build network

USES=		cmake pkgconfig:build qt:4

pre-configure:
	${REINPLACE_CMD} -e 's,lib.*/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
