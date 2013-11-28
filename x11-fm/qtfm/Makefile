# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	qtfm
DISTVERSION=	5.5
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.qtfm.org/

MAINTAINER=	lichray@gmail.com
COMMENT=	Small, lightweight file manager based on pure Qt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix qmake
DOS2UNIX_REGEX=	.*\.(h|cpp)
USE_QT4=	gui network moc_build rcc_build \
		imageformats_run

# Override -A option:
FETCH_ARGS=	-Fpr

STRIP_FILES=	bin/qtfm

post-patch:
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -e s@/usr/@${PREFIX}/@g \
		 -e s@share/qtfm@${DATADIR_REL}@ \
		qtfm.pro src/main.cpp
	@cd ${WRKSRC}/src && \
		${REINPLACE_CMD} -e s@/usr/@${LOCALBASE}/@g \
		icondlg.cpp mainwindow.cpp mymodel.cpp

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
