# New ports collection makefile for:	qtfm
# Date created:				2012-04-29
# Whom:					Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtfm
DISTVERSION=	5.5
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.qtfm.org/

MAINTAINER=	lichray@gmail.com
COMMENT=	A small, lightweight file manager based on pure Qt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(h|cpp)
USE_QT4=	gui network qmake_build moc_build rcc_build \
		imageformats_run

# Override -A option:
FETCH_ARGS=	-Fpr
MAKE_JOBS_SAFE=	yes

STRIP_FILES=	bin/qtfm

post-patch:
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -e s@/usr/@${PREFIX}/@g \
		 -e s@share/qtfm@${DATADIR_REL}@ \
		qtfm.pro src/main.cpp
	@cd ${WRKSRC}/src && \
		${REINPLACE_CMD} -e s@/usr/@${LOCALBASE}/@g \
		icondlg.cpp mainwindow.cpp mymodel.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		${QMAKEFLAGS} qtfm.pro

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
