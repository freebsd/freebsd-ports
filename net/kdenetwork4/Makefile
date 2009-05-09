# New ports collection Makefile for:	kdepim
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications

LIB_DEPENDS=	slp.1:${PORTSDIR}/net/openslp \
		idn.16:${PORTSDIR}/dns/libidn \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		qca.2:${PORTSDIR}/devel/qca \
		otr.4:${PORTSDIR}/security/libotr \
		vncserver.0:${PORTSDIR}/net/libvncserver \
		msn.0:${PORTSDIR}/net-im/libmsn \
		gmp.7:${PORTSDIR}/math/libgmp4 \
		ortp.5:${PORTSDIR}/net/ortp \
		decibel.0:${PORTSDIR}/net-im/decibel \
		meanwhile.1:${PORTSDIR}/net-im/meanwhile \
		speex.1:${PORTSDIR}/audio/speex
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
USE_SQLITE=	yes
QT_COMPONENTS=	corelib opengl dbus qt3support gui network xml porting_build \
		qmake_build moc_build rcc_build uic_build uic3_build
USE_OPENSSL=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	XMMS "Enable XMMS Kopete nowlistening plugin" off

.include <bsd.port.pre.mk>

.if exists(/usr/sbin/pppd)
CMAKE_ARGS+=	-DBUILD_kppp:BOOL=ON
PLIST_SUB+=	KPPP=""
.else
CMAKE_ARGS+=	-DBUILD_kppp:BOOL=OFF
PLIST_SUB+=	KPPP="@comment "
.endif

.if defined(WITH_XMMS)
CMAKE_ARGS+=	-DWITH_Xmms:BOOL=ON
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.else
CMAKE_ARGS+=	-DWITH_Xmms:BOOL=OFF
.endif

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
