# New ports collection makefile for:	kwooty
# Date created:		5 Apr 2010
# Whom:			Mina R Waheeb <syncer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kwooty
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	syncer@gmail.com
COMMENT=	Usenet binary downloader for KDE4

RUN_DEPENDS=	${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/par2:${PORTSDIR}/archivers/par2cmdline \
		${LOCALBASE}/bin/7z:${PORTSDIR}/archivers/p7zip

USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|g' \
		${WRKSRC}/src/preferences/kwootysettings.kcfg
	${REINPLACE_CMD} -e 's|PreferencesServer::MAX_SERVERS|5|g' \
		${WRKSRC}/src/preferences/*.cpp \
		${WRKSRC}/src/widgets/*.cpp

.include <bsd.port.mk>
