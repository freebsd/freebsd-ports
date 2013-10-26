# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca \
		ktorrent:${PORTSDIR}/net-p2p/libktorrent \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		mms.0:${PORTSDIR}/net/libmms \
		jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdehier kdelibs kdeprefix libkonq pimlibs workspace \
		automoc4 ontologies strigi
USES=		cmake:outsource
USE_OPENSSL=	yes
USE_QT4=	corelib gui sql \
		moc_build qmake_build rcc_build uic_build
USE_SQLITE=	yes
USE_XORG=	x11 xdamage xext xscrnsaver xtst
USE_XZ=		yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	XDG_CONFIG_HOME=/dev/null
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

CMAKE_ARGS+=	-DBUILD_kopete=off \
		-DBUILD_krdc=off \
		-DBUILD_krfb=off

OPTIONS_DEFINE=	KOPETE KRDC KRFB
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
KOPETE_DESC=	Multi-protocol instant messenger
KRDC_DESC=	RDP and VNC client for KDE
KRFB_DESC=	VNC server for KDE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKOPETE}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kopete:${PORTSDIR}/net-im/kopete-kde4
.endif

.if ${PORT_OPTIONS:MKRDC}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/krdc:${PORTSDIR}/net/krdc
.endif

.if ${PORT_OPTIONS:MKRFB}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/krfb:${PORTSDIR}/net/krfb
.endif

.include <bsd.port.mk>
