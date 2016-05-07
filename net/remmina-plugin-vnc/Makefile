# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	6
PKGNAMESUFFIX=	-vnc

COMMENT=	Remmina plugin for VNC protocol

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libvncserver.so:net/libvncserver

USES=		jpeg

MASTERDIR=	${.CURDIR}/../remmina-plugins

PLIST_SUB+=	ICONS="" SSH=""

.include "${MASTERDIR}/Makefile"
