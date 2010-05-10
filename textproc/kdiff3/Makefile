# New ports collection makefile for:	kdiff3
# Date created:		2003/01/03
# Whom:			Heiner Eichmann <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kdiff3
PORTVERSION=	0.9.95
CATEGORIES=	textproc kde
MASTER_SITES=	SF

MAINTAINER=	brucec@FreeBSD.org
COMMENT=	A KDE4 graphical frontend for diff

USE_KDE4=	kdebase kdeprefix kdehier automoc4
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
