# $FreeBSD$

PORTNAME=	minitube
DISTVERSION=	2.9
PORTREVISION=	2
CATEGORIES=	multimedia www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TV-like client for YouTube

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	flaviotordini
USE_GL=		gl
USE_QT=		core dbus declarative gui network phonon4 script sql widgets \
		buildtools_build imageformats_run sql-sqlite3_run
QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE} \
		DEFINES+=APP_GOOGLE_API_KEY="${MINITUBE_GOOGLE_API_KEY}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	qt:5
NLS_USE=	QT=linguisttools_build

pre-everything::
	@${CAT} ${PKGMESSAGE}

post-patch:
# Remove BOM
	@${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		${WRKSRC}/src/aggregatevideosource.cpp
	@${REINPLACE_CMD} -e 's|/usr/include|/usr/local/include|g' \
		${WRKSRC}/minitube.pro

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/minitube.pro

.include <bsd.port.mk>
