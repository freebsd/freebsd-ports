# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca \
		otr.4:${PORTSDIR}/security/libotr3 \
		ktorrent:${PORTSDIR}/net-p2p/libktorrent \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		mms.0:${PORTSDIR}/net/libmms \
		jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdehier kdelibs kdeprefix libkonq pimlibs workspace \
		automoc4 ontologies strigi
KDE4_BUILDENV=	yes
USE_OPENSSL=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_SQLITE=	yes
USE_XORG=	x11 xdamage xext xscrnsaver xtst
USE_XZ=		yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DBUILD_kopete=off \
		-DBUILD_krdc=off \
		-DBUILD_krfb=off

OPTIONS_DEFINE=	KOPETE KRDC KRFB
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
KOPETE_DESC=	Multi-protocol instant messenger
KRDC_DESC=	RDP and VNC client for KDE
KRFB_DESC=	VNC server for KDE

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800074
CMAKE_ARGS+=	-DBUILD_kppp:BOOL=OFF
PLIST_SUB+=	KPPP="@comment "
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-CMakeLists.txt
CMAKE_ARGS+=	-DBUILD_kppp:BOOL=ON
PLIST_SUB+=	KPPP=""
.endif

.if ${PORT_OPTIONS:MKOPETE}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kopete:${PORTSDIR}/net-im/kopete-kde4
.endif

.if ${PORT_OPTIONS:MKRDC}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/krdc:${PORTSDIR}/net/krdc
.endif

.if ${PORT_OPTIONS:MKRFB}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/krfb:${PORTSDIR}/net/krfb
.endif

.include <bsd.port.post.mk>
