# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-vnc

COMMENT=	Remmina plugin for VNC protocol

BUILD_DEPENDS=	${LOCALBASE}/include/gcrypt.h:${PORTSDIR}/security/libgcrypt
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		gnutls:${PORTSDIR}/security/gnutls

MASTERDIR=	${.CURDIR}/../remmina-plugins

PLIST_SUB+=	ICONS="" SSH=""

.include "${MASTERDIR}/Makefile"
