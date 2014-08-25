# $FreeBSD$

PORTNAME=	phprecipebook
PORTVERSION=	3.01
PORTREVISION=	1
CATEGORIES=	www deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION:C/\..*//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Small php webapp to manage your recipes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.TXT

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	xml
WANT_PHP_WEB=	yes
SUB_FILES=	pkg-message

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
USES+=		pgsql
.endif

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

do-install:
	${MV} ${WRKSRC}/custom_inc.php ${WRKSRC}/custom_inc.php.sample
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.include <bsd.port.mk>
