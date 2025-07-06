PORTNAME=	rocinante
DISTVERSION=	1.0.20250714
CATEGORIES=	sysutils

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Rocinante is a lightweight configuration management software
WWW=		https://github.com/bastillebsd/rocinante

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bastillebsd

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PREFIX}/bin/rocinante ${STAGEDIR}${PREFIX}/bin

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc \
		 ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	(cd ${WRKSRC}/${PREFIX}/libexec/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}${PREFIX}/etc/rocinante.conf ${STAGEDIR}${PREFIX}/etc/rocinante.conf.sample

.include <bsd.port.mk>
