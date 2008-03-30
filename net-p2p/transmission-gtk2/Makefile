# New ports collection makefile for:	transmission-gtk2
# Date created:				11 February 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-gtk2

COMMENT=	A free BitTorrent client written from scratch in C with GTK+2

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

MASTERDIR=	${.CURDIR}/../transmission
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnometarget gnomehack gtk20 desktopfileutils intlhack
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	${GCONFIGURE} \
		--disable-cli \
		--disable-daemon \
		--enable-gtk

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
MAN1=		transmission.1

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TryExec=.*||g ; /^$$/d' \
		${WRKSRC}/gtk/transmission.desktop.in

post-install: general-install
	@-update-desktop-database

.include "${MASTERDIR}/Makefile"
