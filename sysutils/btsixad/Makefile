PORTNAME=	btsixad
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://althenia.net/files/

MAINTAINER=	aaz@q-fu.com
COMMENT=	Driver for Sixaxis gamepad connected over Bluetooth
WWW=		http://althenia.net/btsixad

LICENSE=	BSD2CLAUSE

USES=		uidfix

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

PLIST_FILES=	sbin/btsixad \
		etc/rc.d/btsixad \
		etc/devd/btsixad.conf \
		share/man/man8/btsixad.8.gz

.include <bsd.port.mk>
