# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qstardict
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://qstardict.ylsoftware.com/files/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 based dictionary program (stardict clone)

USES=		dos2unix pkgconfig qmake
USE_BZIP2=	yes
USE_QT4=	gui network xml uic_build moc_build rcc_build
DOS2UNIX_FILES=	qstardict.pri

DICPATH=	${LOCALBASE}/share/stardict/dic

OPTIONS_DEFINE=	DBUS DOCS NLS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
QMAKE_ARGS+=	NO_TRANSLATIONS=1
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.else
QMAKE_ARGS+=	NO_DBUS=1
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|g" \
		${WRKSRC}/qstardict.pri
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e "/^INSTALLS/s|docs||g" \
		${WRKSRC}/qstardict.pro
.endif
	@${REINPLACE_CMD} -e "s|/usr/share/stardict/dic|${DICPATH}|g" \
		-e "s|glib.*\.h|glib.h|g" \
		${WRKSRC}/plugins/stardict/stardict.cpp

.include <bsd.port.mk>
