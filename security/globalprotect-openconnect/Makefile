PORTNAME=	globalprotect-openconnect
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.9
PORTREVISION=	1
CATEGORIES=	security net-vpn

MAINTAINER=	guru@unixarea.de
COMMENT=	OpenConnect GUI for GlobalProtect protocol
WWW=		https://github.com/yuezk/GlobalProtect-openconnect

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenconnect.so:security/openconnect \
		libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake:noninja desktop-file-utils qt:5
USE_GITHUB=	yes
USE_QT=		buildtools core dbus declarative gui location network printsupport qmake:build webchannel webengine websockets widgets

GH_ACCOUNT=	yuezk
GH_PROJECT=	GlobalProtect-openconnect
GH_TUPLE+=	itay-grudev:SingleApplication:v3.3.0:sa/3rdparty/SingleApplication
GH_TUPLE+=	SergiusTheBest:plog:1.1.6:plog/3rdparty/plog

ETCDIR=		${PREFIX}/etc/gpservice

pre-configure:
	${REINPLACE_CMD} -e 's|/etc/gpservice|${PREFIX}&|g' \
		${WRKSRC}/GPClient/settingsdialog.ui \
		${WRKSRC}/GPService/CMakeLists.txt \
		${WRKSRC}/GPService/gpservice.cpp

post-stage:
	${MV} ${STAGEDIR}${ETCDIR}/gp.conf ${STAGEDIR}${ETCDIR}/gp.conf.sample
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
