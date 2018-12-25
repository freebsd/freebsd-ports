# $FreeBSD$

PORTNAME=	kde-gtk-config
PORTVERSION=	2.2.1
PORTREVISION=	5
CATEGORIES=	x11-themes kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GTK2 and GTK3 Configurator for KDE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake gettext kde:4 pkgconfig qt:4 tar:xz
USE_GNOME=	gtk20 gtk30
USE_KDE=	automoc4 kdelibs
USE_QT=		moc_build qmake_build rcc_build uic_build

post-patch:
	${REINPLACE_CMD} -e '/^install/s,KDE4_LIBEXEC_INSTALL_DIR,LIBEXEC_INSTALL_DIR,g' \
		${WRKSRC}/gtk*proxies/CMakeLists.txt

.include <bsd.port.mk>
