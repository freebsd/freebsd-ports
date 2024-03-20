PORTNAME=	debian-keyring
PORTVERSION=	2024.02.28
CATEGORIES=	security
MASTER_SITES=	https://salsa.debian.org/${PORTNAME}/keyring/-/archive/${PORTVERSION}/
DISTNAME=	keyring_${PORTVERSION}

MAINTAINER=	jinking.this@gmail.com
COMMENT=	GPG keys for Debian package signature verification
WWW=		https://bugs.debian.org/debian-keyring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

COMMIT_HASH=	14725d14e2d29d48c459c196f0013a0f61d0a45f
WRKSRC=		${WRKDIR}/keyring-${PORTVERSION}-${COMMIT_HASH}

do-build:
	cd ${WRKSRC} && ${MAKE} all
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/output/keyrings/debian-*.gpg ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
