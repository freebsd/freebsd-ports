# $FreeBSD$

PORTNAME=	minitube
PORTVERSION=	2.0
CATEGORIES=	multimedia www
MASTER_SITES=	http://flavio.tordini.org/files/minitube/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	TV-like client for YouTube

USE_QT4=	gui network xml dbus phonon phonon-gst \
		moc_build rcc_build imageformats_run
USE_GSTREAMER=	ffmpeg
USES=		qmake
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE}
QMAKE_PRO=	${WRKSRC}/${PORTNAME}.pro

STRIP_FILES=	bin/minitube

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,$$$$PKGDATADIR,${DATADIR},g' ${QMAKE_PRO}
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${QMAKE_PRO}
.endif

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
