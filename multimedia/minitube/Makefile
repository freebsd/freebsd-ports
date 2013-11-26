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

STRIP_FILES=	bin/minitube

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USE=	QT4=linguist_build

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e 's,$$$$PKGDATADIR,${DATADIR},g' ${WRKSRC}/minitube.pro
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/minitube.pro
.endif

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
