# New ports collection makefile for:	minitube
# Date created:		2009-08-15
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minitube
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	multimedia www
MASTER_SITES=	http://flavio.tordini.org/files/minitube/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A native YouTube client

USE_QT_VER=	4
QT_COMPONENTS=	gui network xml dbus phonon phonon-gst \
		qmake_build moc_build rcc_build imageformats_run
USE_GSTREAMER=	ffmpeg
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

QMAKE_ARGS=	-recursive PREFIX=${PREFIX} QMAKE_LRELEASE=${LRELEASE} ${QMAKE_PRO}
QMAKE_PRO=	${WRKSRC}/${PORTNAME}.pro
LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

STRIP_FILES=	bin/minitube

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,$$$$PKGDATADIR,${DATADIR},g' ${QMAKE_PRO}
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${QMAKE_PRO}
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
