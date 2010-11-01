# New ports collection makefile for:	nagvis
# Date created:				5 October 2010
# Whom:					Andrew 'derfi' Sidorov
#
# $FreeBSD$
#

PORTNAME=	nagvis
PORTVERSION=	1.5.4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/NagVis%201.5/

MAINTAINER=	derfi@vei.ru
COMMENT=	NagVis is a visualization addon for Nagios

RUN_DEPENDS=	ndo2db-3x:${PORTSDIR}/net-mgmt/ndoutils

LICENSE=	GPLv2

OPTIONS=	GRAPHVIZ "graphviz is needed for automaps" off

NO_BUILD=	yes
USE_PHP=	gd gettext mbstring mysql session json pdo pdo_sqlite
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5

.include <bsd.port.options.mk>

WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
SUB_LIST+=	WWW_OWNER=${WWW_OWNER} WWW_GROUP=${WWW_GROUP}
SUB_FILES+=	pkg-install

.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

post-extract:
	@${RM} -f ${WRKSRC}/.gitignore ${WRKSRC}/install.sh ${WRKSRC}/INSTALL

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|@NAGVIS_WEB@|/nagvis|g' \
		-e 's|@NAGVIS_PATH@|${WWWDIR}|g' \
		${WRKSRC}/etc/apache2-nagvis.conf-sample
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/nagvis/|${WWWDIR}/|' \
		${WRKSRC}/etc/nagvis.ini.php-sample

do-install:
	@${CP} -R ${WRKSRC} ${WWWDIR}
	@${MKDIR} ${WWWDIR}/var/tmpl/cache
	@${MKDIR} ${WWWDIR}/var/tmpl/compile
	@${MKDIR} ${WWWDIR}/share/var

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL

.include <bsd.port.mk>
