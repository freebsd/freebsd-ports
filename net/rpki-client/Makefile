PORTNAME=	rpki-client
DISTVERSION=	9.6
CATEGORIES=	net
MASTER_SITES=	OPENBSD
MASTER_SITE_SUBDIR=rpki-client

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Resource Public Key Infrastructure (RPKI) implementation from OpenBSD
WWW=		https://www.rpki-client.org/

LICENSE=	ISCL

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Does not support broken OS with small time_t

BUILD_DEPENDS=	rsync>0:net/rsync
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libtls.so:security/libretls
RUN_DEPENDS=	rsync>0:net/rsync

USES=		libtool pkgconfig ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libtls=libtls

LDFLAGS+=	-lpthread

USERS=		_rpki-client
GROUPS=		${USERS}

PLIST_SUB=	USERS="${USERS}"

.include <bsd.port.mk>
