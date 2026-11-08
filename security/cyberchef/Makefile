PORTNAME=	cyberchef
DISTVERSION=	11.5.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/gchq/CyberChef/releases/download/v${DISTVERSION}/
DISTNAME=	CyberChef_8cd426dd4f40f1423912d5fad91b578a86a65112

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Cyber operations within a web browser
WWW=		https://github.com/gchq/CyberChef/

LICENSE=	APACHE20

USES=		cpe zip
CPE_VENDOR=	gchq

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/CyberChef_v${DISTVERSION}.html \
		${STAGEDIR}${WWWDIR}/index.html
	cd ${WRKSRC} && ${COPYTREE_SHARE} "images modules assets" \
		${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
