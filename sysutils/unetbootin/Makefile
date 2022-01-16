# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	unetbootin
PORTVERSION=	702
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Bootable Live USB creator for various Linux distributions

LICENSE=	GPLv2+

RUN_DEPENDS=	7z:archivers/p7zip \
		syslinux:sysutils/syslinux \
		mke2fs:sysutils/e2fsprogs

USES=		qt:5
USE_QT=		buildtools_build linguisttools_build qmake_build \
		core gui network widgets
QMAKE_ARGS=	DEFINES+=LOCALBASE=\\\\\\\"${LOCALBASE}\\\\\\\"

NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/,${PREFIX}/,g' \
		${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's,this->setWindowTitle(UNETBOOTINB,& \
		" ${PORTVERSION}",' ${WRKSRC}/unetbootin.cpp

do-configure:
	cd ${CONFIGURE_WRKSRC} && ${LUPDATE} unetbootin.pro \
		     && ${LRELEASE} unetbootin.pro \
		     && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

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
