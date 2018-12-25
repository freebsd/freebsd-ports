# $FreeBSD$

PORTNAME=	ksysguardd
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde kde-applications
DISTNAME=	kde-workspace-${PORTVERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE System Guard Daemon

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde-workspace-kde4/distinfo
USES=		cmake:insource kde:4 tar:xz
CMAKE_ARGS+=	-DBIN_INSTALL_DIR:STRING="${PREFIX}/bin" \
		-DSYSCONF_INSTALL_DIR:STRING="${PREFIX}/etc"

KDE_APPLICATIONS_VERSION=	15.08.0

EXTRACT_AFTER_ARGS=	'${DISTNAME}/ksysguard/${PORTNAME}' \
			'${DISTNAME}/ksysguard/example/${PORTNAME}rc' \
			'${DISTNAME}/ksysguard/gui/SignalIDs.h'

WRKSRC_SUBDIR=	ksysguard/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		etc/${PORTNAME}rc

pre-build:
	${REINPLACE_CMD} -e 's/<config-workspace.h>/"config-${PORTNAME}.h"/' \
		${WRKSRC}/${PORTNAME}.c

.include <bsd.port.mk>
