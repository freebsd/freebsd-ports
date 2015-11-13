# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	krusader
DISTVERSION=	2.4.0-beta3
PORTREVISION=	4
CATEGORIES=	x11-fm kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Twin panel file manager for KDE, like midnight or norton commander

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource gettext tar:bzip2
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
