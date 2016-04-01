# Created by: Jonathan Chen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	psi
PORTVERSION=	0.15
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/Psi/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 based Jabber client

LIB_DEPENDS=	libqca.so:devel/qca \
		libminizip.so:archivers/minizip

HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
USES=		pkgconfig tar:bzip2
USE_QT4=	gui network xml imageformats_run \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	xscrnsaver

CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${LOCALBASE} \
		--disable-growl --verbose
CONFIGURE_ENV=	QMAKE_ARGS='${QMAKE_ARGS}'
DESTDIRNAME=	INSTALL_ROOT

OPTIONS_DEFINE=	ASPELL ENCHANT DBUS DEBUG
OPTIONS_DEFAULT=	ENCHANT DBUS
OPTIONS_SUB=	yes # DEBUG

DEBUG_CONFIGURE_ON=	--debug
DEBUG_CONFIGURE_OFF=	--release  --no-separate-debug-info

DBUS_USE=	QT4=dbus
DBUS_CONFIGURE_OFF=	--disable-qdbus

ASPELL_DESC=	Use aspell for spell checking
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ON=	--with-aspell-inc=${LOCALBASE}/include \
			--with-aspell-lib=${LOCALBASE}/lib
ASPELL_CONFIGURE_OFF=	--disable-aspell

ENCHANT_DESC=	Use Enchant for spell checking
ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant
ENCHANT_CONFIGURE_OFF=	--disable-enchant

post-configure:
# Reorder paths to always include internal socks.h (PR: 192270)
	${REINPLACE_CMD} -e '/^INCPATH/s,-I\.,-I\. -Icutestuff,' \
		${WRKSRC}/iris/src/irisnet/noncore/Makefile
	${REINPLACE_CMD} -e '/^INCPATH/s,-I\.,-I\. -I../irisnet/noncore/cutestuff,' \
		${WRKSRC}/iris/src/xmpp/Makefile

.include <bsd.port.mk>
