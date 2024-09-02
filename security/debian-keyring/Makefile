PORTNAME=	debian-keyring
DISTVERSION=	2024.08.28
CATEGORIES=	security
MASTER_SITES=	https://salsa.debian.org/${PORTNAME}/keyring/-/archive/${DISTVERSION}/
DISTNAME=	keyring_${DISTVERSION}

MAINTAINER=	jinking.this@gmail.com
COMMENT=	GPG keys for Debian package signature verification
WWW=		https://bugs.debian.org/debian-keyring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
PORTSCOUT=	skipv:2026.00.00

COMMIT_HASH=	f25a83b884b03b5cfb764e11ab38ef80a1c71e99
WRKSRC=		${WRKDIR}/keyring-${DISTVERSION}-${COMMIT_HASH}

do-build:
	cd ${WRKSRC} && ${MAKE} all
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/output/keyrings/debian-*.gpg ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
