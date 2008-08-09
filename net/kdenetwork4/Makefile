# New ports collection Makefile for:	kdepim
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications

BUILD_DEPENDS=	${LOCALBASE}/lib/libvncserver.a:${PORTSDIR}/net/libvncserver
#		decibel:${PORTSDIR}/net-im/decibel
LIB_DEPENDS=	slp:${PORTSDIR}/net/openslp \
		idn:${PORTSDIR}/dns/libidn \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		qca.2:${PORTSDIR}/devel/qca \
		otr.4:${PORTSDIR}/security/libotr
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs pimlibs workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
USE_SQLITE=	yes
QT_COMPONENTS=	corelib opengl moc rcc uic dbus qt3support gui network porting uic3 xml
USE_OPENSSL=	yes

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
