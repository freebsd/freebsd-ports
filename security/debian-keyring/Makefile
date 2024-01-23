PORTNAME=	debian-keyring
PORTVERSION=	2023.12.24
CATEGORIES=	security
MASTER_SITES=	https://salsa.debian.org/${PORTNAME}/keyring/-/archive/${PORTVERSION}/
DISTNAME=	keyring_${PORTVERSION}

MAINTAINER=	jinking.this@gmail.com
COMMENT=	GPG keys for Debian package signature verification
WWW=		https://bugs.debian.org/debian-keyring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/keyring-${PORTVERSION}-582acae4bb0cdf90967b0b492deb3ccf9f8b5ec2

do-build:
	cd ${WRKSRC} && ${MAKE} all
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/output/keyrings/debian-*.gpg ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
