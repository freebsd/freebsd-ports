# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ultracopier
PORTVERSION=	1.2.1.0
CATEGORIES=	x11-fm
MASTER_SITES=	http://files.first-world.info/ultracopier/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced file copier

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake tar:xz
USE_QT5=	buildtools_build linguisttools_build \
		core gui network widgets xml
QMAKE_ARGS=	LRELEASE="${LRELEASE}" ultracopier-core.pro

WRKSRC=		${WRKDIR}/${PORTNAME}-src

PLIST_FILES=	bin/ultracopier share/applications/ultracopier.desktop \
		share/icons/hicolor/16x16/apps/ultracopier.png \
		share/icons/hicolor/128x128/apps/ultracopier.png

post-patch:
	@${GREP} -Rl Q_OS_LINUX ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		s/Q_OS_LINUX/Q_OS_UNIX/
	@${REINPLACE_CMD} -e '/crackedVersion=/s,false,true,' \
		${WRKSRC}/EventDispatcher.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for dimensions in 16x16 128x128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${dimensions}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/ultracopier-${dimensions}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${dimensions}/apps/ultracopier.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/ultracopier.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
