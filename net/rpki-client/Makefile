PORTNAME=	rpki-client
DISTVERSION=	9.2
CATEGORIES=	net
MASTER_SITES=	OPENBSD
MASTER_SITE_SUBDIR=rpki-client

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Resource Public Key Infrastructure (RPKI) implementation from OpenBSD
WWW=		https://www.rpki-client.org/

LICENSE=	ISCL

BUILD_DEPENDS=	rsync>0:net/rsync
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libtls.so:security/libretls
RUN_DEPENDS=	rsync>0:net/rsync

USES=		libtool pkgconfig ssl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-libtls=libtls

USERS=		_rpki-client
GROUPS=		${USERS}

PLIST_SUB=	USERS="${USERS}"

.include <bsd.port.mk>
