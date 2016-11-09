# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ricochet
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Anonymous peer-to-peer instant messenger

LICENSE=	RICOCHET
LICENSE_NAME=	Ricochet
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libprotobuf.so:devel/protobuf
RUN_DEPENDS=	tor:security/tor

BROKEN_FreeBSD_9_amd64=	does not build

USE_GITHUB=	yes
GH_ACCOUNT=	ricochet-im

USES=		compiler:c++11-lib gmake pkgconfig qmake ssl
USE_GL=		gl
USE_QT5=	core gui network qml quick widgets multimedia buildtools_build linguisttools_build
QMAKE_ARGS+=	DEFINES+=RICOCHET_NO_PORTABLE OPENSSLDIR=${LOCALBASE}

PLIST_FILES=	bin/ricochet \
		share/applications/ricochet.desktop \
		share/icons/hicolor/48x48/apps/ricochet.png \
		share/icons/hicolor/scalable/apps/ricochet.svg

post-patch:
	@${REINPLACE_CMD} -E 's| -fsanitize=[a-z-]+| |g' \
		${WRKSRC}/hardened.pri

.include <bsd.port.mk>
