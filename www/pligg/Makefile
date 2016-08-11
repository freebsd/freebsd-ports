# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pligg
PORTVERSION=	2.0.2
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Web2.0 CMS

LICENSE=	CCA30
LICENSE_NAME=	Creative Commons Attribution 3.0 Unported Copyright
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_powerpc64=	Does not build

USES=		cpe
CPE_PRODUCT=	pligg_cms
CPE_VENDOR=	pligg

USE_GITHUB=	yes
GH_ACCOUNT=	Pligg
GH_PROJECT=	pligg-cms

USE_PHP=	mysql

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

post-install:
	@if [ ! -f ${STAGEDIR}${WWWDIR}/settings.php ]; then \
	${CP} -p ${STAGEDIR}${WWWDIR}/settings.php.default ${STAGEDIR}${WWWDIR}/settings.php; fi

	@if [ ! -f ${STAGEDIR}${WWWDIR}/libs/dbconnect.php ]; then \
	${CP} -p ${STAGEDIR}${WWWDIR}/libs/dbconnect.php.default \
		${STAGEDIR}${WWWDIR}/libs/dbconnect.php; fi

	@${CHMOD} 666 ${STAGEDIR}${WWWDIR}/settings.php
	@${ECHO_CMD} '@exec ${CHMOD} 666 ${WWWDIR}/settings.php' \
		>> ${TMPPLIST}

	@${CHMOD} 666 ${STAGEDIR}${WWWDIR}/libs/dbconnect.php
	@${ECHO_CMD} '@exec ${CHMOD} 666 ${WWWDIR}/libs/dbconnect.php' \
		>> ${TMPPLIST}

	@${CHMOD} 655 ${STAGEDIR}${WWWDIR}/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 655 ${WWWDIR}/config.php' \
		>> ${TMPPLIST}

.for d in admin/backup cache avatars/groups_uploaded avatars/user_uploaded languages
	@${CHMOD} -R 777 ${STAGEDIR}${WWWDIR}/${d}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${WWWDIR}/${d}' >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
