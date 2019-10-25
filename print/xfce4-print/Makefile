# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-print
PORTVERSION=	4.6.1
PORTREVISION=	16
CATEGORIES=	print xfce
MASTER_SITES=	XFCE/archive
DISTNAME=	xfprint-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Print system support for the Xfce Desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	a2ps:print/a2ps
RUN_DEPENDS=	a2ps:print/a2ps
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce:gtk2 xorg
USE_GNOME=	cairo glib20 gtk20 intltool
USE_LDCONFIG=	yes
USE_XFCE=	libgui xfconf
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		LETTER NLS
OPTIONS_SINGLE=		PRINTMETHOD
OPTIONS_SINGLE_PRINTMETHOD=	LPR CUPS
OPTIONS_DEFAULT=	LPR
OPTIONS_SUB=		yes

LETTER_DESC=	Use letter paper format instead of A4
LPR_DESC=	LPR printing system support

CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

LETTER_CONFIGURE_ENABLE=letter
LPR_CONFIGURE_ENABLE=	bsdlpr
LPR_CONFIGURE_WITH=	printcap=/etc/printcap

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-patch:
	@${REINPLACE_CMD} '/_LDADD =/s/=/= -lX11/' \
		${WRKSRC}/xfprint/Makefile.in \
		${WRKSRC}/xfprint-manager/Makefile.in

.include <bsd.port.mk>
