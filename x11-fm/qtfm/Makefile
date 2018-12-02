# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	qtfm
DISTVERSION=	5.5
PORTREEVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.qtfm.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, lightweight file manager based on pure Qt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		dos2unix qmake qt:4
DOS2UNIX_REGEX=	.*\.(h|cpp)
USE_QT=		gui network moc_build rcc_build \
		imageformats_run

post-patch:
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -e s@/usr/@${PREFIX}/@g \
		 -e s@share/qtfm@${DATADIR_REL}@ \
		qtfm.pro src/main.cpp
	@cd ${WRKSRC}/src && \
		${REINPLACE_CMD} -e s@/usr/@${LOCALBASE}/@g \
		icondlg.cpp mainwindow.cpp mymodel.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qtfm

.include <bsd.port.mk>
