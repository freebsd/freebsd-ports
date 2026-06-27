PORTNAME=	fetion
DISTVERSION=	0.98.5.2
PORTREVISION=	9
CATEGORIES=	net-im
MASTER_SITES=	http://www.logvinov.ru/files/dist/fetion/ \
		LOCAL/avl
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fetion protocol plugin for libpurple
WWW=		https://sourceforge.net/projects/fetion/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Fetion service is no longer available after 2022
EXPIRATION_DATE=	2026-07-31

LIB_DEPENDS=	libpurple.so:net-im/libpurple

USES=		libtool localbase:ldflags pkgconfig tar:bzip2

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/purple-2/libfetion.so

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion -Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.post.mk>
