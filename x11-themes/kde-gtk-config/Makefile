# $FreeBSD$

PORTNAME=	kde-gtk-config
PORTVERSION=	2.1.1
CATEGORIES=	x11-themes kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GTK2 and GTK3 Configurator for KDE

USE_BZIP2=	yes
USES=		cmake:outsource
USE_GNOME=	gtk20 gtk30
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build

post-patch:
	cd ${WRKSRC}/src && \
	${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},g' \
		appearancegtk3.cpp \
		appearancegtk2.cpp \
		iconthemesmodel.cpp
	${REINPLACE_CMD} -e '/oxygen/s,/usr,${KDE4_PREFIX},g' \
		${WRKSRC}/src/ui/*.ui

.include <bsd.port.mk>
