# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jreen
PORTVERSION=	1.1.1
#PORTREVISION=	0
CATEGORIES=	net-im

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Extensible Qt-based asynchronious Jabber library

LICENSE=	GPLv2

LIB_DEPENDS=	qca:${PORTSDIR}/devel/qca \
		speex:${PORTSDIR}/audio/speex

CMAKE_ARGS=	-DCMAKE_COLOR_MAKEFILE:BOOL="OFF"

GH_ACCOUNT=	euroelessar
GH_COMMIT=	388621f
GH_PROJECT=	jreen
GH_TAGNAME=	v${PORTVERSION}

REINPLACE_ARGS=	-e 's,-lspeex,-L${LOCALBASE}/lib &,1' -i.bak

USE_CMAKE=	yes
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
USE_QT4=	moc_build qmake_build rcc_build network

post-configure:
	@${REINPLACE_CMD} ${WRKSRC}/CMakeFiles/jreen.dir/link.txt

.include <bsd.port.mk>
