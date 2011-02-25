# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	4.0.5
PORTREVISION=	1
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		qca.2:${PORTSDIR}/devel/qca \
		tag.1:${PORTSDIR}/audio/taglib \
		ktorrent.2:${PORTSDIR}/net-p2p/libktorrent

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	SYNDICATION "Enable RSS/Atom plugin" on \
		PLASMA "Enable Ktorrent Plasma applet" on

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/libktorrent-2.2.8.so)
IGNORE=	fails to build with net-p2p/ktorrent2 installed. Deinstall it first
.endif

.if !defined(WITHOUT_SYNDICATION)
USE_KDE4+=	pimlibs
PLIST_SUB+=	SYNDICATION=""
.else
CMAKE_ARGS+=	-DENABLE_SYNDICATION_PLUGIN=false
PLIST_SUB+=	SYNDICATION="@comment "
.endif

.if !defined(WITHOUT_PLASMA)
USE_KDE4+=	workspace
PLIST_SUB+=	PLASMA=""
.else
PLIST_SUB+=	PLASMA="@comment "
.endif

pre-configure:
.if defined(WITHOUT_PLASMA)
	${REINPLACE_CMD} -e '/add_subdirectory(applet)/d' \
		${WRKSRC}/plasma/CMakeLists.txt
	${REINPLACE_CMD} -e '/^macro_kt_plugin.*shutdown/d' \
		${WRKSRC}/plugins/CMakeLists.txt
.endif

.include <bsd.port.mk>
