# New ports collection makefile for:	knemo
# Date created:				Sat Jan 22 00:20:26 CET 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	knemo
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	12956-${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Network monitor for KDE

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
USE_KDE4=	kdeprefix kdelibs automoc4

MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not build on 7.X
.endif

.include <bsd.port.post.mk>
