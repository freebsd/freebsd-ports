PORTNAME=	rpki-client
DISTVERSION=	6.7p1
CATEGORIES=	net

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Resource Public Key Infrastructure (RPKI) implementation from OpenBSD

LICENSE=	ISCL

BUILD_DEPENDS=	rsync>0:net/rsync
RUN_DEPENDS=	rsync>0:net/rsync

USES=		autoreconf libtool ssl

USERS=		_rpki-client
GROUPS=		${USERS}
PLIST_SUB=	USERS="${USERS}"

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-portable ${PORTNAME}-openbsd:openbsd
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}:openbsd
GH_SUBDIR=	openbsd:openbsd

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSREL:R} < 12 && ${SSL_DEFAULT} == "base"
BROKEN=		requires OpenSSL 1.1.1, upgrade to FreeBSD 12.x/13.x or add DEFAULT_VERSIONS+=ssl=[openssl|libressl*] to /etc/make.conf
.endif

pre-configure:
	cd ${WRKSRC} && ${SH} update.sh

.include <bsd.port.post.mk>
