# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	kmess
PORTVERSION=	2.0.6.2
PORTREVISION=	11
CATEGORIES=	net-im kde
MASTER_SITES=	SF/${PORTNAME}/Latest%20versions/${PORTVERSION}/

MAINTAINER=	syncer@gmail.com
COMMENT=	MSN Messenger client for KDE

LIB_DEPENDS=	libqca.so:devel/qca \
		libgif.so:graphics/giflib

USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdelibs libkonq automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
USES=		cmake gettext tar:bzip2

.include <bsd.port.mk>
