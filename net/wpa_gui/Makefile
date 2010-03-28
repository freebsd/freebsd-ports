# New ports collection makefile for:	wpa_gui
# Date created:		2009-01-10
# Whom:			Ilya Bakulin <webmaster@kibab.com>
#
# $FreeBSD$
#

PORTNAME=	wpa_gui
PORTVERSION=	0.5.11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/
DISTNAME=	wpa_supplicant-${PORTVERSION}

MAINTAINER=	webmaster@kibab.com
COMMENT=	QT GUI for wpa_supplicant

PLIST_FILES=	sbin/${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/wpa_gui-qt4
USE_QT_VER=	4
QT_COMPONENTS=	gui qt3support qmake_build moc_build uic_build

HAS_CONFIGURE=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} -unix PREFIX=${PREFIX} ${PORTNAME}.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
