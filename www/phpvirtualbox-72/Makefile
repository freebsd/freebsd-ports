PORTNAME=	phpvirtualbox
DISTVERSION=	7.2-1
PORTREVISION=	2
CATEGORIES=	www
SUFFIX=		-72
PKGNAMESUFFIX=	${SUFFIX}${PHP_PKGNAMESUFFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# Fix missing NVRAM file when creating new VM with EFI:
# https://github.com/phpvirtualbox/phpvirtualbox/issues/364
PATCHFILES+=	2d806b480c28c4343ceda12ac0f8614713eddaec.patch:-p1
# Disable Page Fusion feature, does not work in VirtualBox 7.2:
# https://github.com/phpvirtualbox/phpvirtualbox/issues/363
PATCHFILES+=	ab759b995472b98bda9e49050dff65c11e0a62b7.patch:-p1

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox
WWW=		https://github.com/phpvirtualbox/phpvirtualbox/

LICENSE=	GPLv3

USES=		php:flavors
USE_GITHUB=	yes
USE_PHP=	session simplexml soap xml

ETCDIR=		${WWWDIR}
WWWDIR=		${PREFIX}/www/${PORTNAME}${SUFFIX}
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^7\.2\.

post-patch:
	@${MV} ${WRKSRC}/phpvirtualbox.conf ${WRKSRC}/phpvirtualbox${SUFFIX}.conf
	@${REINPLACE_CMD} -e 's#Alias /phpvirtualbox#Alias /phpvirtualbox${SUFFIX}#' \
		-e 's#/usr/share/phpvirtualbox#${WWWDIR}#g' \
		${WRKSRC}/phpvirtualbox${SUFFIX}.conf

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
