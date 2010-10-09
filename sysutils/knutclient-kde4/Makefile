# New ports collection makefile for:	KDE Nut Client
# Date created:				Mon Apr 28 05:30:59 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	knutclient
PORTVERSION=	1.0.3
CATEGORIES=	sysutils kde
MASTER_SITES=	ftp://ftp.buzuluk.cz/pub/alo/knutclient/stable/ \
		http://www.vg.kernel.org/pub/mirrors/gentoo/source/distfiles/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	A visual client for UPS system NUT

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz

USE_CMAKE=	yes
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
LATEST_LINK=	knutclient-kde4

.include <bsd.port.mk>
