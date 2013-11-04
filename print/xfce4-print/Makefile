# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-print
PORTVERSION=	4.6.1
PORTREVISION=	10
CATEGORIES=	print xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/archive/xfprint/${PORTVERSION:R}
DISTNAME=	xfprint-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Print system support for the Xfce Desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps
RUN_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig gmake pathfix
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	configenv libgui libutil xfconf

OPTIONS_DEFINE=	LETTER
OPTIONS_DEFAULT=	LPR
OPTIONS_SINGLE=	PRINTMETHOD
OPTIONS_SINGLE_PRINTMETHOD=	LPR CUPS
LETTER_DESC=	Use letter paper format instead of A4
LPR_DESC=	LPR printing system support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCUPS}
CONFIGURE_ARGS+=--enable-cups
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
CONFIGURE_ARGS+=--disable-cups
PLIST_SUB+=	CUPS="@comment "
.endif

.if ${PORT_OPTIONS:MLPR}
CONFIGURE_ARGS+=--enable-bsdlpr --with-printcap=/etc/printcap
PLIST_SUB+=	LPR=""
.else
CONFIGURE_ARGS+=--disable-bsdlpr
PLIST_SUB+=	LPR="@comment "
.endif

.if ${PORT_OPTIONS:MLETTER}
CONFIGURE_ARGS+=--enable-letter
.else
CONFIGURE_ARGS+=--disable-letter
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/@LDFLAGS@/& -Wl,-E/' ${WRKSRC}/xfprint/Makefile.in \
		 ${WRKSRC}/xfprint-manager/Makefile.in

.include <bsd.port.post.mk>
