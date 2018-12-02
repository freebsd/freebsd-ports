# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unetbootin
PORTVERSION=	661
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Bootable Live USB creator for various Linux distributions

LICENSE=	GPLv2+

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	7z:archivers/p7zip \
		syslinux:sysutils/syslinux \
		mke2fs:sysutils/e2fsprogs

USES=	qt:4
USE_QT=		linguisttools_build moc_build qmake_build uic_build \
		corelib gui network
QMAKE_ARGS=	DEFINES+=LOCALBASE=\\\\\\\"${LOCALBASE}\\\\\\\"

NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/,${PREFIX}/,g' \
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
