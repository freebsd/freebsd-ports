# $FreeBSD$

PORTNAME=	metronome
DISTVERSION=	0.9.0
CATEGORIES=	net-mgmt dns

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Client-side java script to render graphs w/o depending on graphite

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	eigen>0:math/eigen3
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		autoreconf:build libtool:build pathfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ahupowerdns

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

pre-configure:
	(cd ${WRKSRC}; ./bootstrap )

.include <bsd.port.mk>
