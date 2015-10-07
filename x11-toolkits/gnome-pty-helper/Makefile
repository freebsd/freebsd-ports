# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gnome-pty-helper/Makefile 18942 2013-12-08 01:31:37Z kwm $

PORTNAME=	gnome-pty-helper
PORTREVISION=	0
PKGNAMESUFFIX=	#empty

COMMENT=	utmp/wtmp/lastlog helper program for the vte Terminal widget

VTE3_SLAVE=	yes

MASTERDIR=	${.CURDIR}/../../x11-toolkits/vte3
CONFIGURE_WRKSRC=	${WRKSRC}/gnome-pty-helper
BUILD_WRKSRC=	${WRKSRC}/gnome-pty-helper
INSTALL_WRKSRC=	${WRKSRC}/gnome-pty-helper
PLIST=		${.CURDIR}/pkg-plist
USE_GNOME=	gnomeprefix
CONFIGURE_ARGS=	# empty
#PATCH_STRIP=	-p1
#EXTRA_PATCHES+=	${MASTERDIR}/files/patch-gnome-pty-helper_gnome-pty-helper.c

.include "${MASTERDIR}/Makefile"
