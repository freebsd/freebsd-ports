# $FreeBSD$

PORTNAME=	saaghar
PORTVERSION=	1.0.94
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/saaghar/Source%20Code/:saaghar \
		SF/ganjoor/s3db:ganjoor
DISTFILES=	Saaghar-${PORTVERSION}.tar.gz:saaghar	\
		ganjoor-s3db-910612.zip:ganjoor
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Persian poetry software

LICENSE=	GPLv3

EXTRACT_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

USES=		qmake
USE_QT4=	gui network sql xml sql-sqlite3_run \
		moc_build rcc_build uic_build
WRKSRC=		${WRKDIR}/Saaghar

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDEBUG}
QMAKE_ARGS+=	-config release
.endif

post-extract:
	${UNZIP_CMD} -d ${WRKDIR}/ganjoor \
		${DISTDIR}/${DIST_SUBDIR}/ganjoor-s3db-910612.zip

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/saaghar|${PREFIX}/share/saaghar|g' \
		${WRKSRC}/mainwindow.cpp \
		${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		${WRKSRC}/QGanjoorDbBrowser.cpp \
		${WRKSRC}/QGanjoorDbStuff.h \
		${WRKSRC}/mainwindow.cpp

post-install:
	cd ${WRKDIR}/ganjoor && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
