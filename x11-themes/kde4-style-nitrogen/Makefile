# New ports collection makefile for:   nitrogen
# Date created:                        Thu Dec  3 04:21:05  EST 2009
# Whom:                                Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	nitrogen
PORTVERSION=	1.0.5
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde4-style-
DISTFILES=	112652-kde4-kstyle-nitrogen-${PORTVERSION}-Source.tar.gz

MAINTAINER=	steve@mouf.net
COMMENT=	KDE style with animations

WRKSRC=		${WRKDIR}/kde4-kstyle-nitrogen-${PORTVERSION}-Source
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

.include <bsd.port.mk>
