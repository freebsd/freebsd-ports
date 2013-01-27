# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	tellico
PORTVERSION=	2.3.7
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		yaz:${PORTSDIR}/net/yaz \
		exempi:${PORTSDIR}/textproc/exempi \
		kcddb:${PORTSDIR}/multimedia/kdemultimedia4 \
		qjson:${PORTSDIR}/devel/qjson

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_KDE4=	kdehier kdelibs kdeprefix libksane pimlibs \
		automoc4 qimageblitz
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
