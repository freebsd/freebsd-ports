# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	tellico
PORTVERSION=	2.3.12
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	libexempi.so:textproc/exempi \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libpoppler-qt4.so:graphics/poppler-qt4 \
		libqjson.so:devel/qjson \
		libtag.so:audio/taglib \
		libyaz.so:net/yaz

USES=		cmake gettext kde:4 pkgconfig shared-mime-info tar:bzip2
USE_GNOME=	libxml2 libxslt
USE_KDE=	kdelibs libksane pimlibs soprano \
		automoc4 qimageblitz libkcddb libkcompactdisc
USE_QT4=	corelib dbus gui network phonon svg xml \
		qmake_build moc_build uic_build rcc_build

.include <bsd.port.mk>
