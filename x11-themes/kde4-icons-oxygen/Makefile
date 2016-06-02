# $FreeBSD$

PORTNAME=	oxygen
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11-themes kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kde4-icons-
DISTNAME=	${PORTNAME}-icons-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The Oxygen icon theme for KDE

USE_KDE4=	# blank, needed to get KDE4_VERSION
USES=		cmake:outsource tar:xz
INSTALL_TARGET=	install
EXTRACT_AFTER_ARGS=	--exclude '${DISTNAME}/scalable'

.include <bsd.port.mk>
