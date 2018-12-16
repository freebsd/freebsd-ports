# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	tellico
PORTVERSION=	2.3.12
PORTREVISION=	7
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE

LICENSE=	GPLv2

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libexempi.so:textproc/exempi \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libqjson.so:devel/qjson@qt4 \
		libtag.so:audio/taglib \
		libyaz.so:net/yaz

USES=		cmake gettext kde:4 pkgconfig python:run \
		qt:4 shared-mime-info shebangfix tar:bzip2
USE_GNOME=	libxml2 libxslt
USE_KDE=	kdelibs libksane pimlibs soprano \
		automoc4 qimageblitz libkcddb libkcompactdisc
USE_QT=		corelib dbus gui network phonon svg xml \
		qmake_build moc_build uic_build rcc_build

SHEBANG_FILES=	src/fetch/scripts/bedetheque.py \
		src/fetch/scripts/dark_horse_comics.py \
		src/fetch/scripts/fr.allocine.py \
		src/fetch/scripts/ministerio_de_cultura.py

.include <bsd.port.mk>
