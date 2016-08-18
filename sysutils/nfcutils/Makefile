# $FreeBSD$

PORTNAME=	nfcutils
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	dengtooling@gmail.com
COMMENT=	Listing NFC devices and in-field tags or targets

LICENSE=	GPLv3

LIB_DEPENDS=	libnfc.so:devel/libnfc

USES=		autoreconf gmake libtool pkgconfig tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	terence-deng
MAKE_ENV+=	MKDIR="${MKDIR}"

HAS_CONFIGURE=	true

PLIST_FILES=	bin/lsnfc

.include <bsd.port.mk>
