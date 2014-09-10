# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	knutclient
PORTVERSION=	1.0.4
PORTREVISION=	6
CATEGORIES=	sysutils kde
MASTER_SITES=	ftp://ftp.buzuluk.cz/pub/alo/knutclient/stable/ \
		http://www.ringofsaturn.com/distfiles/ \
		http://www.vg.kernel.org/pub/mirrors/gentoo/source/distfiles/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Visual client for UPS system NUT

LIB_DEPENDS=	libqimageblitz.so:${PORTSDIR}/x11/qimageblitz

CONFLICTS=	knutclient-0.*
USES=		cmake gettext
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	corelib gui qmake_build moc_build rcc_build uic_build
LATEST_LINK=	knutclient-kde4

.include <bsd.port.mk>
