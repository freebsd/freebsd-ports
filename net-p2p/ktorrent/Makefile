# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	3.2.2
DISTVERSIONSUFFIX=-1
PORTREVISION=	2
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		qca.2:${PORTSDIR}/devel/qca \
		streamanalyzer.0:${PORTSDIR}/deskutils/strigi \
		tag.6:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qt3support dbus gui network sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

OPTIONS=	SYNDICATION "Enable RSS/Atom plugin" on \
		PLASMA "Enable Ktorrent Plasma applet" on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

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
.endif

.include <bsd.port.post.mk>
