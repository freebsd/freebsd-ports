# $FreeBSD$

PORTNAME=	btsixad
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://althenia.net/files/

MAINTAINER=	aaz@q-fu.com
COMMENT=	Driver for Sixaxis gamepad connected over Bluetooth

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcuse4bsd.so:multimedia/cuse4bsd-kmod

USES=		uidfix

PLIST_FILES=	sbin/btsixad \
		etc/rc.d/btsixad \
		etc/devd/btsixad.conf \
		man/man8/btsixad.8.gz

.include <bsd.port.mk>
