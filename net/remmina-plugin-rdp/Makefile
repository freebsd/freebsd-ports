# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-rdp

COMMENT=	Remmina plugin for RDP protocol

LIB_DEPENDS=	libfreerdp-core.so:${PORTSDIR}/net/freerdp

MASTERDIR=	${.CURDIR}/../remmina-plugins

PLIST_SUB+=	ICONS="" SSH=""

.include "${MASTERDIR}/Makefile"
