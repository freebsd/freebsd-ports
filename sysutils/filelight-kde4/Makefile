# New ports collection Makefile for:	filelight
# Date created:				2009-10-09
# Whom:					Rusty Nejdl <rnejdl@ringofsaturn.com>
#
# $FreeBSD$
#

PORTNAME=	filelight
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTNAME=	99561-${PORTNAME}-${PORTVERSION}rc3
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}rc3

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Represent a file system as a set of concentric segmented-rings

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFG=	yes
LATEST_LINK=	filelight-kde4

.include <bsd.port.mk>
