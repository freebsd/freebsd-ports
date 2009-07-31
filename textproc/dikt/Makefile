# New ports collection makefile for:	dikt
# Date created:			28-12-2008
# Whom:				Goran Tal <goran.tal@gmail.com>
#
# $FreeBSD$

PORTNAME=	dikt
PORTVERSION=	1g
PORTREVISION=	1
CATEGORIES=	textproc net kde
MASTER_SITES=	http://diktv1.googlepages.com/	\
		LOCAL/beech
EXTRACT_SUFX=	.tbz

MAINTAINER=	goran.tal@gmail.com
COMMENT=	Dictionary for KDE4

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network svg xml \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

PLIST_FILES=	bin/dikt \
		share/applications/kde4/dikt.desktop \
		share/apps/dikt/diktui.rc \
		share/kde4/services/dict.protocol
PLIST_DIRS=	share/apps/dikt

.include <bsd.port.mk>
