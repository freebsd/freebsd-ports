# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
DISTVERSION=	0.12
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	A Qt-based Jabber client

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui iconengines imageformats qt3support \
		inputmethods moc network rcc script svg uic xml

CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt4/mkspecs/freebsd-g++ \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LDFLAGS=${PTHREAD_LIBS} \
		KDEDIR=${LOCALBASE}
CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${LOCALBASE} \
		--disable-growl --disable-ghbnr
MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

post-patch:
	#fix build when libzip is installed
	cd ${WRKSRC}/src/tools/zip && ${LN} zip.h psi-zip.h

post-install:
	${STRIP_CMD} ${PREFIX}/bin/psi

.include <bsd.port.mk>
