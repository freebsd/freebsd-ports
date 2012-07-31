# New ports collection makefile for:	krename
# Date created:				11 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	krename
PORTVERSION=	4.0.9
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KDE4%20${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Very powerful batch file renamer for KDE

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		exiv2.12:${PORTSDIR}/graphics/exiv2 \
		podofo.0:${PORTSDIR}/graphics/podofo

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
