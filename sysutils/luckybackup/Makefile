# New ports collection makefile for:	luckybackup
# Date created:				2009-04-28
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$

PORTNAME=	luckybackup
PORTVERSION=	0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	QT4 frontend to the backup utility rsync

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build rcc_build uic_build
MAKE_ENV=	INSTALL_ROOT=${PREFIX}
MAKE_JOBS_SAFE=	yes

MAN8=		luckybackup.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/usr||g' -e '/INSTALLS/s|debianmenu ||' \
		-e '/manpage/s|share/||' ${WRKSRC}/luckybackup.pro
	${REINPLACE_CMD} -e 's|/usr/bin/||g' -e 's|/usr/share/pixmaps/||g' \
		${WRKSRC}/menu/*.desktop
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/global.h ${WRKSRC}/src/scheduleDialog.cpp

do-configure:
	cd ${WRKSRC} && ${QMAKE}

.include <bsd.port.post.mk>
