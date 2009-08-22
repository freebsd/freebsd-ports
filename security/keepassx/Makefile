# New ports collection makefile for:	keepassx
# Date created:	   18 September 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	KeePassX
PORTVERSION=	0.3.4
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Cross Platform Password Manager

DATADIR=	${PREFIX}/share/${PORTNAME:L}
WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build qt3support_build rcc_build \
		corelib gui xml
HAS_CONFIGURE=	yes
USE_XORG=	xt inputproto xtst xrender xrandr xfixes xcursor\
		xext x11 sm ice xi

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} \
		INCLUDEPATH+=${LOCALBASE}/include LIBS+=-L${LOCALBASE}/lib \
		keepassx.pro

.include <bsd.port.mk>
