# Created by: Mina R Waheeb <syncer@gmail.com>
# $FreeBSD$

PORTNAME=	kwooty
PORTVERSION=	0.8.3
PORTREVISION=	6
CATEGORIES=	net kde
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	syncer@gmail.com
COMMENT=	Usenet binary downloader for KDE4

RUN_DEPENDS=	${LOCALBASE}/bin/unrar:archivers/unrar \
		${LOCALBASE}/bin/par2:archivers/par2cmdline \
		${LOCALBASE}/bin/7z:archivers/p7zip

USES=		cmake gettext kde:4
USE_KDE=	kdelibs automoc4 workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|g' \
		${WRKSRC}/src/preferences/kwootysettings.kcfg
	${REINPLACE_CMD} -e 's|PreferencesServer::MAX_SERVERS|5|g' \
		${WRKSRC}/src/preferences/*.cpp \
		${WRKSRC}/src/widgets/*.cpp

.include <bsd.port.mk>
