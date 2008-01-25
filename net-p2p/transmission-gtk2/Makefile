# New ports collection makefile for:	transmission-gtk2
# Date created:				11 February 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
PKGNAMESUFFIX=	-gtk2

COMMENT=	A free BitTorrent client written from scratch in C with GTK+2

MASTERDIR=	${.CURDIR}/../transmission
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnometarget gnomehack gtk20 desktopfileutils intlhack
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--without-wx

CUSTOM_SUBDIRS=	third-party libtransmission gtk po
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
MAN1=		transmission.1

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TryExec=.*||g ; /^$$/d' \
		${WRKSRC}/gtk/transmission.desktop.in
	@${REINPLACE_CMD} -e 's|[$$]GMSGFMT[$$]|$$INTLTOOL_MSGFMT$$|g' \
		${WRKSRC}/configure

post-install: general-install
	@-update-desktop-database

.include "${MASTERDIR}/Makefile"
