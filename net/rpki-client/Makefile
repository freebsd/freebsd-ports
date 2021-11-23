PORTNAME=	rpki-client
DISTVERSION=	7.5
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Resource Public Key Infrastructure (RPKI) implementation from OpenBSD

LICENSE=	ISCL

BUILD_DEPENDS=	rsync>0:net/rsync
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libtls.so:security/libretls
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		rsync>0:net/rsync

USES=		autoreconf libtool pkgconfig ssl

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-portable ${PORTNAME}-openbsd:openbsd
GH_SUBDIR=	openbsd:openbsd
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}:openbsd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libtls=libtls

USERS=		_rpki-client
GROUPS=		${USERS}
PLIST_SUB=	USERS="${USERS}"

pre-configure:
	cd ${WRKSRC} && ${SH} update.sh

.include <bsd.port.mk>
