## New ports collection makefile for:	kshowmail
# Date created:			Sat Oct 18 14:01:21 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	kshowmail
PORTVERSION=	4.1
CATEGORIES=	mail kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20for%20KDE4/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 mail checker for KDE

LICENSE=	GPLv2

USE_KDE4=	automoc4 kdehier kdeprefix kdelibs pimlibs
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5_BUILD=yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
