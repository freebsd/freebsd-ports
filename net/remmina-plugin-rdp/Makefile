# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-rdp

COMMENT=	Remmina plugin for RDP protocol

LIB_DEPENDS=	libfreerdp2.so:net/freerdp

USES=		gnome xorg
USE_GNOME=	cairo
USE_XORG=	ice sm x11 xext

MASTERDIR=	${.CURDIR}/../remmina-plugins

.include "${MASTERDIR}/Makefile"
