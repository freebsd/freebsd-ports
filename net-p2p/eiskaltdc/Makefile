# New ports collection makefile for: net-p2p/eiskaltdc
# Date created:		28 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdcpp
PORTVERSION=	2.0.2
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	A Direct Connect client QT GUI

LIB_DEPENDS=	upnp.3:${PORTSDIR}/devel/upnp \
		boost_system.4:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

PROJECTHOST=	eiskaltdc

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_CMAKE=	yes
USE_QT_VER=	4
USE_OPENSSL=	yes
QT_COMPONENTS=	gui xml dbus network sql qmake_build uic_build \
		moc_build rcc_build linguist_build
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

OPTIONS=	ASPELL "Spell checking support" off

.include <bsd.port.options.mk>

.if definede(WITH_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=on
.else
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=off
.endif

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,share/man/,man/,g' \
		${WRKSRC}/${PORTNAME}/CMakeLists.txt

.include <bsd.port.mk>
