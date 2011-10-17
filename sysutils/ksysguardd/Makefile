# New ports collection makefile for:	ksysguardd
# Date created:				5 March 2011
# Whom:					avilla@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ksysguardd
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src/
DISTNAME=	kde-workspace-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE System Guard Daemon

DISTINFO_FILE=	${PORTSDIR}/x11/kde4-workspace/distinfo
USE_BZIP2=	yes
USE_KDE4=	kdeprefix kdehier
USE_CMAKE=	yes
CMAKE_ARGS+=	-DBIN_INSTALL_DIR:STRING="${PREFIX}/bin" \
		-DSYSCONF_INSTALL_DIR:STRING="${PREFIX}/etc"
MAKE_JOBS_SAFE=	yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - \
		'${DISTNAME}/ksysguard/${PORTNAME}' \
		'${DISTNAME}/ksysguard/example/${PORTNAME}rc' \
		'${DISTNAME}/ksysguard/gui/SignalIDs.h'

WRKSRC=		${WRKDIR}/${DISTNAME}/ksysguard/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		etc/${PORTNAME}rc

pre-build:
	${REINPLACE_CMD} -e 's/<config-workspace.h>/"config-${PORTNAME}.h"/' \
		${WRKSRC}/${PORTNAME}.c

.include <bsd.port.mk>
