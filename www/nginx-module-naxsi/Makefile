PORTNAME=	nginx-module-naxsi
DISTVERSION=	1.7.20261026
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the naxsi module for the NGINX ports
WWW=		https://github.com/wargio/naxsi

LICENSE=	GPLv3+ LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LICENSES/LGPL-3.0-only.txt

USES=		cpe
CPE_VENDOR=	wargio
CPE_PRODUCT=	naxsi
CPE_TARGET_SW=	nginx

USE_GITHUB=	yes
GH_ACCOUNT=	wargio
GH_PROJECT=	naxsi
GH_TAGNAME=	4ea4701

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODSRC=	naxsi_src naxsi_rules LICENSES

post-extract:
	@${RMDIR} ${WRKSRC}/naxsi_src/libinjection

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${_MODSRC}" ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
