PORTNAME=	debian-keyring
DISTVERSION=	2026.08.27
CATEGORIES=	security

MAINTAINER=	jinking.this@gmail.com
COMMENT=	GPG keys for Debian package signature verification
WWW=		https://bugs.debian.org/debian-keyring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_PROJECT=	keyring

NO_ARCH=	yes
PORTSCOUT=	skipv:2026.00.00

do-build:
	cd ${WRKSRC} && ${MAKE_CMD} all

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/output/keyrings/debian-*.gpg ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
