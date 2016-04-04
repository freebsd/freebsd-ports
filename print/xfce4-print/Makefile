# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-print
PORTVERSION=	4.6.1
PORTREVISION=	14
CATEGORIES=	print xfce
MASTER_SITES=	XFCE/src/archive/xfprint/${PORTVERSION:R}
DISTNAME=	xfprint-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Print system support for the Xfce Desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	a2ps:print/a2ps
RUN_DEPENDS=	a2ps:print/a2ps

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake libtool pathfix pkgconfig xfce tar:bzip2
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	libgui xfconf

OPTIONS_DEFINE=	LETTER
OPTIONS_DEFAULT=	LPR
OPTIONS_SINGLE=	PRINTMETHOD
OPTIONS_SINGLE_PRINTMETHOD=	LPR CUPS
LETTER_DESC=	Use letter paper format instead of A4
LPR_DESC=	LPR printing system support
CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CONFIGURE_ENABLE=	cups
LPR_CONFIGURE_ENABLE=	bsdlpr
LPR_CONFIGURE_WITH=	printcap=/etc/printcap
LETTER_CONFIGURE_ENABLE=	letter
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} '/_LDADD =/s/=/= -lX11/' \
		${WRKSRC}/xfprint/Makefile.in \
		${WRKSRC}/xfprint-manager/Makefile.in

.include <bsd.port.mk>
