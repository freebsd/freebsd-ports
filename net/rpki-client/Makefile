PORTNAME=	rpki-client
DISTVERSION=	7.2
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

.include <bsd.port.pre.mk>

.if ${OSREL:R} < 12 && ${SSL_DEFAULT} == "base"
BROKEN=		requires OpenSSL 1.1.1, upgrade to FreeBSD 12.x/13.x or add DEFAULT_VERSIONS+=ssl=[openssl|libressl*] to /etc/make.conf
.endif

pre-configure:
	cd ${WRKSRC} && ${SH} update.sh

.include <bsd.port.post.mk>
