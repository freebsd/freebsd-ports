PORTNAME=	rocinante
DISTVERSION=	0.1.20220714
CATEGORIES=	sysutils

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Rocinante is a lightweight configuration management software

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bastillebsd
GH_TAGNAME=	ace6eea

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PREFIX}/bin/rocinante ${STAGEDIR}${PREFIX}/bin

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	(cd ${WRKSRC}/${PREFIX}/libexec/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}${PREFIX}/etc/rocinante.conf ${STAGEDIR}${PREFIX}/etc/rocinante.conf.sample

.include <bsd.port.mk>
