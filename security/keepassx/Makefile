# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	KeePassX
PORTVERSION=	0.4.4
CATEGORIES=	security
MASTER_SITES=	https://www.keepassx.org/releases/${PORTVERSION}/ \
		http://www.keepassx.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross Platform Password Manager

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${PORTVERSION}

DEPRECATED=	Use keepassx2 or keepassxc instead
EXPIRATION_DATE=	2018-08-12

PORTSCOUT=	ignore

USES=		desktop-file-utils qmake qt:4 shared-mime-info
USE_QT=		moc_build uic_build qt3support_build rcc_build \
		corelib gui xml
USE_XORG=	xt inputproto xtst xrender xrandr xfixes xcursor\
		xext x11 sm ice xi

QMAKE_ARGS+=	INCLUDEPATH+=${LOCALBASE}/include LIBS+=-L${LOCALBASE}/lib

.include <bsd.port.mk>
