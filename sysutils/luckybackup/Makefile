# $FreeBSD$

PORTNAME=	luckybackup
PORTVERSION=	0.4.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/source

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	QT4 frontend to the backup utility rsync

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync

USES=		qmake
USE_QT4=	gui network moc_build rcc_build uic_build

post-patch:
	${REINPLACE_CMD} -e 's|/usr|$$$${PREFIX}|g' -e '/INSTALLS/s|debianmenu ||' \
		-e '/manpage/s|share/||' -e 's|QMAKE_STRIP.*|QMAKE_STRIP = ${STRIP_CMD}|g' \
		${WRKSRC}/luckybackup.pro
	${REINPLACE_CMD} -e 's|/usr/bin/||g' -e 's|/usr/share/pixmaps/||g' \
		${WRKSRC}/menu/*.desktop
	${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/src/executenow.cpp
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/global.h \
		${WRKSRC}/src/scheduleDialog.cpp

.include <bsd.port.mk>
