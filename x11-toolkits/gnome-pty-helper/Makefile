# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gnome-pty-helper/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-pty-helper
PORTREVISION=	0

COMMENT=	utmp/wtmp/lastlog helper program for the vte Terminal widget

VTE3_SLAVE=	yes

MASTERDIR=	${.CURDIR}/../../x11-toolkits/vte3
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
USES=		pathfix
USE_GNOME=	gnomeprefix
CONFIGURE_ARGS=	# empty
PATCH_STRIP=	-p1
EXTRA_PATCHES+=	${MASTERDIR}/files/patch-gnome-pty-helper_Makefile.in \
		${MASTERDIR}/files/patch-gnome-pty-helper_gnome-pty-helper.c
LATEST_LINK=	${PORTNAME}

.include "${MASTERDIR}/Makefile"
