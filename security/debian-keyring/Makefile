PORTNAME=	debian-keyring
DISTVERSION=	2025.03.23
CATEGORIES=	security

MAINTAINER=	jinking.this@gmail.com
COMMENT=	GPG keys for Debian package signature verification

WWW=		https://bugs.debian.org/debian-keyring
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_PROJECT=	keyring

NO_ARCH=	yes
PORTSCOUT=	skipv:2026.00.00

do-build:
	cd ${WRKSRC} && ${MAKE} all
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/output/keyrings/debian-*.gpg ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
