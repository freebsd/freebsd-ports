PORTNAME=	fetion
PORTVERSION=	0.98.5.2
PORTREVISION=	8
CATEGORIES=	net-im
MASTER_SITES=	http://www.logvinov.ru/files/dist/fetion/ \
		LOCAL/avl
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fetion protocol plugin for libpurple
WWW=		https://sourceforge.net/projects/fetion/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpurple.so:net-im/libpurple

USES=		libtool localbase:ldflags pkgconfig tar:bzip2

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/purple-2/libfetion.so

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
