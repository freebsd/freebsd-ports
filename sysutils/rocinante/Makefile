PORTNAME=	rocinante
DISTVERSION=	1.1.2
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
	${INSTALL_SCRIPT} ${WRKSRC}/${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/${PREFIX}/libexec && \
		${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/libexec)
	${INSTALL_DATA} ${WRKSRC}${PREFIX}/etc/rocinante.conf \
		${STAGEDIR}${PREFIX}/etc/rocinante.conf.sample

.include <bsd.port.mk>
