PORTNAME=	cyberchef
DISTVERSION=	11.4.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/gchq/CyberChef/releases/download/v${DISTVERSION}/
DISTNAME=	CyberChef_49d1a5634a67a3b806c6db0fdca7dcecb41a776c

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
