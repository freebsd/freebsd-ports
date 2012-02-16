# New ports collection makefile for: bangarang
# Date created:        11 June 2010
# Whom:                Daniel Nebdal <dnebdal@gmail.com>
#
# $FreeBSD$

PORTNAME=	bangarang
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dnebdal@gmail.com
COMMENT=	A media player for KDE4

LICENSE=	GPLv3

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib

PROJECTHOST=	bangarangissuetracking
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_KDE4=	automoc4 kdelibs kdebase kdeprefix

MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}

.include <bsd.port.mk>
