PORTNAME=	rpki-client
DISTVERSION=	8.2
CATEGORIES=	net
MASTER_SITES=	https://cdn.openbsd.org/pub/OpenBSD/rpki-client/ \
		https://cloudflare.cdn.openbsd.org/pub/OpenBSD/rpki-client/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Resource Public Key Infrastructure (RPKI) implementation from OpenBSD
WWW=		https://www.rpki-client.org/

LICENSE=	ISCL

BUILD_DEPENDS=	rsync>0:net/rsync
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libtls.so:security/libretls
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		rsync>0:net/rsync

USES=		autoreconf libtool pkgconfig ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libtls=libtls

USERS=		_rpki-client
GROUPS=		${USERS}
PLIST_SUB=	USERS="${USERS}"

.include <bsd.port.mk>
