# New ports collection makefile for:	nagvis
# Date created:				5 October 2010
# Whom:					Andrew 'derfi' Sidorov
#
# $FreeBSD$
#

PORTNAME=	nagvis
PORTVERSION=	1.5.9
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}/NagVis%201.5

MAINTAINER=	derfi@vei.ru
COMMENT=	NagVis is a visualization addon for Nagios

LICENSE=	GPLv2

OPTIONS=	MKLIVESTATUS 	"depend on mk-livestatus broker (preferred)" on \
 		NDO2DB 		"depend on ndo2db broker" off \
		GRAPHVIZ	"graphviz is needed for automaps" off

NO_BUILD=	yes
USE_PHP=	gd gettext mbstring session json pdo pdo_sqlite
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5

.include <bsd.port.options.mk>

WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
DIRMODE?=	750
FILEMODE?=	640

SUB_LIST+=	WWW_OWNER=${WWW_OWNER} WWW_GROUP=${WWW_GROUP} \
		DIRMODE=${DIRMODE} FILEMODE=${FILEMODE}
SUB_FILES+=	pkg-install pkg-deinstall

.if defined(WITH_NDO2DB)
USE_PHP+=	mysql
RUN_DEPENDS+=	ndo2db-3x:${PORTSDIR}/net-mgmt/ndoutils
.endif

.if defined(WITH_MKLIVESTATUS)
RUN_DEPENDS+=	mk-livestatus>=0:${PORTSDIR}/net-mgmt/mk-livestatus
.endif

.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

check-sanity:
.if !defined(WITH_NDO2DB) && !defined(WITH_MKLIVESTATUS)
IGNORE=	please choose at least one nagios broker module
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
	@( cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}/ )

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL

.include <bsd.port.mk>
