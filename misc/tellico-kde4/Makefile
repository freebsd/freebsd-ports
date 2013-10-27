# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	tellico
PORTVERSION=	2.3.8
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		yaz:${PORTSDIR}/net/yaz \
		exempi:${PORTSDIR}/textproc/exempi \
		qjson:${PORTSDIR}/devel/qjson

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_KDE4=	kdehier kdelibs kdeprefix libksane pimlibs \
		automoc4 qimageblitz libkcddb sharedmime
USE_QT4=	qmake_build moc_build uic_build rcc_build
USES=		cmake gettext

NO_STAGE=	yes
.include <bsd.port.mk>
