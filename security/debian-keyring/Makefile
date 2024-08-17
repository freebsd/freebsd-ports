PORTNAME=	debian-keyring
DISTVERSION=	2024.07.30
CATEGORIES=	security
MASTER_SITES=	https://salsa.debian.org/${PORTNAME}/keyring/-/archive/${DISTVERSION}/
DISTNAME=	keyring_${DISTVERSION}

MAINTAINER=	jinking.this@gmail.com
COMMENT=	GPG keys for Debian package signature verification
WWW=		https://bugs.debian.org/debian-keyring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

COMMIT_HASH=	af5c621023eab16ae59102f1d3af7acd17c7bc08
WRKSRC=		${WRKDIR}/keyring-${DISTVERSION}-${COMMIT_HASH}

do-build:
	cd ${WRKSRC} && ${MAKE} all
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/output/keyrings/debian-*.gpg ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
