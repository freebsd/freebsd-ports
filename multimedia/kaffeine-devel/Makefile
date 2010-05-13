# New ports collection Makefile for:	kaffeine-devel
# Date created:				2009-10-06
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	1.0.p.3
PORTREVISION=	3
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine/kaffeine/${DISTNAME}
DISTNAME=	kaffeine-${PORTVERSION:S/.p./-pre/}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	KDE4 version of kaffeine

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine
LATEST_LINK=	${PORTNAME}-devel
USE_KDE4=	kdehier kdeprefix automoc4 kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui phonon svg network dbus xml sql \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's,add_subdirectory(x-test),,' ${WRKSRC}/po/CMakeLists.txt

.include <bsd.port.mk>
