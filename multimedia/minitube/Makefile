# $FreeBSD$

PORTNAME=	minitube
PORTVERSION=	2.4
CATEGORIES=	multimedia www

MAINTAINER=	makc@FreeBSD.org
COMMENT=	TV-like client for YouTube

USE_QT4=	dbus gui network phonon script sql xml \
		moc_build rcc_build imageformats_run
USES=		qmake
USE_GITHUB=	yes
GH_ACCOUNT=	flaviotordini

QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE} \
		DEFINES+=APP_GOOGLE_API_KEY="${MINITUBE_GOOGLE_API_KEY}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USE=	QT4=linguisttools_build

.include <bsd.port.options.mk>

pre-everything::
	@${CAT} ${PKGMESSAGE}

pre-configure:
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/minitube.pro
.endif
# Remove BOM
	${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		 ${WRKSRC}/src/aggregatevideosource.cpp

.include <bsd.port.mk>
