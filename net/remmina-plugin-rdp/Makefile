# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-rdp

COMMENT=	Remmina plugin for RDP protocol

LIB_DEPENDS=	libfreerdp.so:${PORTSDIR}/net/freerdp

MASTERDIR=	${.CURDIR}/../remmina-plugins

BROKEN=		version 1.0.0 is incompatible with freerdp 1.2.x

PLIST_SUB+=	ICONS="" SSH=""

.include "${MASTERDIR}/Makefile"
