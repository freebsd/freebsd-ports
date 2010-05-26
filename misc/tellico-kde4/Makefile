# New ports collection makefile for:	bookcase
# Date created:				11 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	tellico
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		yaz:${PORTSDIR}/net/yaz \
		exempi:${PORTSDIR}/textproc/exempi \
		kcddb:${PORTSDIR}/multimedia/kdemultimedia4 \
		ksane:${PORTSDIR}/graphics/kdegraphics4

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_KDE4=	pimlibs kdelibs kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
