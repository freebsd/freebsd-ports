# $FreeBSD$

PORTNAME=	kde-gtk-config
PORTVERSION=	2.2.1
CATEGORIES=	x11-themes kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GTK2 and GTK3 Configurator for KDE

USES=		cmake:outsource pkgconfig
USE_GNOME=	gtk20 gtk30
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

post-patch:
	${REINPLACE_CMD} -e '/^install/s,KDE4_LIBEXEC_INSTALL_DIR,LIBEXEC_INSTALL_DIR,g' \
		${WRKSRC}/gtk*proxies/CMakeLists.txt

.include <bsd.port.mk>
