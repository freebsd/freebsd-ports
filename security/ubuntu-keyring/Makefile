PORTNAME=	ubuntu-keyring
PORTVERSION=	2021.03.26
CATEGORIES=	security
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/u/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mia-rain@tuta.io
COMMENT=	GPG keys for Ubuntu package signature verification
WWW=		https://bugs.launchpad.net/ubuntu/+filebug

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/debian/copyright

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/keyrings
	${INSTALL_DATA} ${WRKSRC}/keyrings/* ${STAGEDIR}${PREFIX}/share/keyrings/

.include <bsd.port.mk>
