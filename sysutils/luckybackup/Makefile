# $FreeBSD$

PORTNAME=	luckybackup
PORTVERSION=	0.4.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/source

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt frontend to the backup utility rsync

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/license/gpl.txt

RUN_DEPENDS=	rsync:net/rsync

USES=		compiler:c++11-lang gl qmake qt:5

USE_GL=		gl
USE_QT=		core gui network widgets buildtools_build

post-patch:
	${REINPLACE_CMD} -e 's|/usr|$$$${PREFIX}|g' -e '/INSTALLS/s|debianmenu ||' \
		-e '/manpage/s|share/||' -e 's|QMAKE_STRIP.*|QMAKE_STRIP = ${STRIP_CMD}|g' \
		${WRKSRC}/luckybackup.pro
	${REINPLACE_CMD} -e 's|/usr/bin/||g' -e 's|/usr/share/pixmaps/||g' \
		${WRKSRC}/menu/*.desktop
	${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/src/executenow.cpp
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/global.cpp \
		${WRKSRC}/src/scheduleDialog.cpp

.include <bsd.port.mk>
