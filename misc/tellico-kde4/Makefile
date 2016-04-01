# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	tellico
PORTVERSION=	2.3.11
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	libtag.so:audio/taglib \
		libpoppler-qt4.so:graphics/poppler-qt4 \
		libyaz.so:net/yaz \
		libexempi.so:textproc/exempi \
		libqjson.so:devel/qjson

USE_KDE4=	kdelibs kdeprefix libksane pimlibs \
		automoc4 qimageblitz libkcddb libkcompactdisc
USE_QT4=	qmake_build moc_build uic_build rcc_build
USES=		cmake gettext pkgconfig shared-mime-info tar:bzip2

.include <bsd.port.mk>
