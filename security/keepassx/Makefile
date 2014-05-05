# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	KeePassX
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME:tl}/KeePassX/${PORTVERSION}/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Cross Platform Password Manager

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${PORTVERSION}

USES=		qmake shared-mime-info
USE_QT4=	moc_build uic_build qt3support_build rcc_build \
		corelib gui xml
USE_XORG=	xt inputproto xtst xrender xrandr xfixes xcursor\
		xext x11 sm ice xi

QMAKE_ARGS+=	INCLUDEPATH+=${LOCALBASE}/include LIBS+=-L${LOCALBASE}/lib

.include <bsd.port.mk>
