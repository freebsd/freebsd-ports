PORTNAME=	luckybackup
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/source

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt frontend to the backup utility rsync
WWW=		https://luckybackup.sourceforge.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/license/gpl.txt

RUN_DEPENDS=	rsync:net/rsync \
		pkexec:sysutils/polkit

USES=		compiler:c++11-lang gl qmake qt:5

USE_GL=		gl
USE_QT=		core gui network widgets buildtools:build

post-patch:
	${REINPLACE_CMD} -e 's|/usr|$$$${PREFIX}|g' -e '/INSTALLS/s|debianmenu ||' \
		-e 's|QMAKE_STRIP.*|QMAKE_STRIP = ${STRIP_CMD}|g' \
		${WRKSRC}/luckybackup.pro
	${REINPLACE_CMD} -e 's|/usr/bin/||g' -e 's|/usr/share/pixmaps/||g' \
		${WRKSRC}/menu/*.desktop
	${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/src/executenow.cpp
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/menu/luckybackup-pkexec \
		${WRKSRC}/menu/net.luckybackup.su.policy \
		${WRKSRC}/src/global.cpp \
		${WRKSRC}/src/scheduleDialog.cpp

.include <bsd.port.mk>
