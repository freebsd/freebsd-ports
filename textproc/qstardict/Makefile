# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qstardict
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://qstardict.ylsoftware.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 4 based dictionary program (stardict clone)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix pkgconfig qmake tar:bzip2
USE_QT4=	corelib gui network xml uic_build moc_build rcc_build
USE_GNOME=	glib20
USE_XORG=	x11
DOS2UNIX_FILES=	qstardict.pri

# Path to dictionaries installed by stardict-* ports
DICPATH=	${LOCALBASE}/share/stardict/dic

OPTIONS_DEFINE=	DBUS DOCS NLS
OPTIONS_DEFAULT=DBUS
OPTIONS_SUB=	yes

DBUS_USE=	QT4=dbus
DBUS_QMAKE_OFF=	NO_DBUS=1

NLS_QMAKE_OFF=	NO_TRANSLATIONS=1

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|g" \
		${WRKSRC}/qstardict.pri
	@${REINPLACE_CMD} -e "s|/usr/share/stardict/dic|${DICPATH}|g" \
		-e "s|glib.*\.h|glib.h|g" \
		${WRKSRC}/plugins/stardict/stardict.cpp

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e "/^INSTALLS/s|docs||g" \
		${WRKSRC}/qstardict.pro

.include <bsd.port.mk>
