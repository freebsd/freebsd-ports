# New ports collection makefile for:	transmission-gtk2
# Date created:				11 February 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-gtk2

COMMENT=	A free BitTorrent client written from scratch in C with GTK+2

MASTERDIR=	${.CURDIR}/../transmission
PLIST=		${.CURDIR}/pkg-plist

USE_XLIB=	yes
USE_GNOME=	gtk20 desktopfileutils
SLAVE_TRANS=	gtk2
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-daemon

MAN1=		transmission-gtk.1
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TARGETS = .cli|#TARGETS = .cli|g' \
		${WRKSRC}/mk/default.mk
	@${REINPLACE_CMD} -e 's|TryExec=.*||g ; /^$$/d' \
		${WRKSRC}/gtk/transmission-gtk.desktop

post-install: general-install
	@-update-desktop-database

.include "${MASTERDIR}/Makefile"
