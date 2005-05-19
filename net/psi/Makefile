# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vsevolod@highsecure.ru
COMMENT=	A Qt-based Jabber client

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	qca.1:${PORTSDIR}/devel/qca
RUN_DEPENDS=	${X11BASE}/lib/plugins/crypto/libqca-tls.so:${PORTSDIR}/security/qca-tls

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_QT_VER=	3

CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LDFLAGS=${PTHREAD_LIBS} \
		KDEDIR=${LOCALBASE}
CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${X11BASE} \
		--with-qca-inc=${X11BASE}/include/plugins/qca \
		--with-qca-lib=${X11BASE}/lib
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

OPTIONS=	KDE "Enable KDE tray support" on

.include <bsd.port.pre.mk>

.if defined(WITH_KDE)
LIB_DEPENDS=	kdecore:${PORTSDIR}/x11/kdelibs3
_NO_KDE_CONFTARGET_HACK=	yes
PLIST_SUB+=	KDE=""
.else
CONFIGURE_ARGS+=	--disable-kde
PLIST_SUB+=	KDE="@comment "
.endif

pre-install:
.if defined(WITH_KDE)
	@for size in 16x16 32x32 48x48; do \
	${MKDIR} ${LOCALBASE}/share/icons/hicolor/${size}/apps; \
	done
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/psi

.include <bsd.port.post.mk>
