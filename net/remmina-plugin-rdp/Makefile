# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-rdp

COMMENT=	Remmina plugin for RDP protocol

LIB_DEPENDS=	libfreerdp.so:${PORTSDIR}/net/freerdp

MASTERDIR=	${.CURDIR}/../remmina-plugins

BROKEN=		version 1.0.0 is incompatible with freerdp 1.2.x
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-12-30

PLIST_SUB+=	ICONS="" SSH=""

.include "${MASTERDIR}/Makefile"
