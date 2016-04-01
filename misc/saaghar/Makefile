# $FreeBSD$

PORTNAME=	saaghar
PORTVERSION=	2.5.0
CATEGORIES=	misc
MASTER_SITES=	SF/saaghar/Source%20Code/:saaghar \
		SF/ganjoor/s3db:ganjoor
DISTFILES=	Saaghar-${PORTVERSION}.tar.gz:saaghar	\
		ganjoor-s3db-930711.zip:ganjoor
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Persian poetry software

LICENSE=	GPLv3

EXTRACT_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip

OPTIONS_DEFINE=	DEBUG

USES=		qmake dos2unix
USE_QT4=	gui network sql xml sql-sqlite3_run \
		moc_build rcc_build uic_build phonon \
		dbus declarative xmlpatterns svg script
WRKSRC=		${WRKDIR}/Saaghar

DOS2UNIX_REGEX=	.*\.([ch]|cpp)

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDEBUG}
QMAKE_ARGS+=	-config release
.endif

post-extract:
	${UNZIP_CMD} -d ${WRKDIR}/ganjoor \
		${DISTDIR}/${DIST_SUBDIR}/ganjoor-s3db-930711.zip

post-patch:
	@${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		${WRKSRC}/src/saagharwindow.cpp \
		${WRKSRC}/src/version.h

post-install:
	cd ${WRKDIR}/ganjoor && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
