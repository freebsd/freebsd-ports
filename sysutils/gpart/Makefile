PORTNAME=	gpart
PORTVERSION=	0.1h
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SUNSITE/system/filesystems \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tries to recover lost partition tables and file systems
WWW=		https://github.com/baruch/gpart/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
PLIST_FILES=	sbin/gpart share/man/man8/gpart.8.gz
CFLAGS+=	-std=c99

OPTIONS_DEFINE=	STATIC
STATIC_LDFLAGS=	-static

.include <bsd.port.mk>
