# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	5
PKGNAMESUFFIX=	-vnc

COMMENT=	Remmina plugin for VNC protocol

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libvncserver.so:${PORTSDIR}/net/libvncserver

MASTERDIR=	${.CURDIR}/../remmina-plugins

PLIST_SUB+=	ICONS="" SSH=""

.include "${MASTERDIR}/Makefile"
