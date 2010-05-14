# New ports collection makefile for:	krusader
# Date created:		21-04-2003
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	krusader
PORTVERSION=	2.2.0.b1
PORTREVISION=	1
CATEGORIES=	x11-fm kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S/.b/-beta/}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-beta/}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A two window file-manager for KDE, like midnight or norton commander

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build \
		rcc_build uic_build
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
MAKE_JOBS_UNSAFE=	yes
LATEST_LINK=	krusader2

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
