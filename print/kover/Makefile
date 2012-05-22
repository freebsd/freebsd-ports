# New ports collection makefile for:	kover
# Date created:			Mon Dec 29 05:07:17 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	kover
PORTVERSION=	4
CATEGORIES=	print kde
MASTER_SITES=	http://lisas.de/kover/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG CD cover printer

LICENSE=	GPLv2

LIB_DEPENDS=	cddb.4:${PORTSDIR}/audio/libcddb \
		cdio.13:${PORTSDIR}/sysutils/libcdio

USE_BZIP2=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5_BUILD=yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kover.1

.include <bsd.port.mk>
