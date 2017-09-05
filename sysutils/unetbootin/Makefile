# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unetbootin
PORTVERSION=	655
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/UNetbootin/${PORTVERSION}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Bootable Live USB creator for various Linux distributions

LICENSE=	GPLv2+

RUN_DEPENDS=	7z:archivers/p7zip \
		syslinux:sysutils/syslinux \
		mke2fs:sysutils/e2fsprogs

USE_QT4=	linguisttools_build moc_build qmake_build uic_build \
		corelib gui network
QMAKE_ARGS=	DEFINES+=LOCALBASE=\\\\\\\"${LOCALBASE}\\\\\\\"

NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,g' \
		${WRKSRC}/main.cpp

do-configure:
	${LUPDATE} ${WRKSRC}/unetbootin.pro
	${LRELEASE} ${WRKSRC}/unetbootin.pro
	cd ${WRKSRC} && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unetbootin ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/unetbootin.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/unetbootin_*.qm ${STAGEDIR}${DATADIR}
.for n in 16 22 24 32 48 64 128 192 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${WRKSRC}/unetbootin_${n}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps/unetbootin.png
.endfor

.include <bsd.port.mk>
