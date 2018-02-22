# Created by: Andrew 'derfi' Sidorov <derfi@vei.ru>
# $FreeBSD$

PORTNAME=	nagvis
PORTVERSION=	1.9.5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.nagvis.org/share/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visualization addon for Nagios

LICENSE=	GPLv2

OPTIONS_DEFINE=	GRAPHVIZ
OPTIONS_SINGLE=	BROKER
OPTIONS_SINGLE_BROKER=	MKLIVESTATUS NDO2DB
OPTIONS_DEFAULT=	MKLIVESTATUS
MKLIVESTATUS_DESC=	Depend on mk-livestatus broker (preferred)
NDO2DB_DESC=	Depend on ndo2db broker
GRAPHVIZ_DESC=	Graphviz is needed for automaps

USES=		gettext php:web
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

NO_BUILD=	yes
USE_PHP=	gd gettext mbstring session json pdo pdo_sqlite

.include <bsd.port.options.mk>

WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
DIRMODE?=	750
FILEMODE?=	640

SUB_LIST+=	WWW_OWNER=${WWW_OWNER} WWW_GROUP=${WWW_GROUP} \
		DIRMODE=${DIRMODE} FILEMODE=${FILEMODE}
SUB_FILES+=	pkg-install pkg-deinstall
PLIST_SUB+=	WWWDIR="${WWWDIR}"

.if ${PORT_OPTIONS:MNDO2DB}
USE_PHP+=	mysql
RUN_DEPENDS+=	ndo2db-3x:net-mgmt/ndoutils
.endif

.if ${PORT_OPTIONS:MMKLIVESTATUS}
RUN_DEPENDS+=	mk-livestatus>=0:net-mgmt/mk-livestatus
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	dot:graphics/graphviz
.endif

post-extract:
	@${RM} ${WRKSRC}/.gitignore ${WRKSRC}/install.sh ${WRKSRC}/INSTALL

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|@NAGVIS_WEB@|/nagvis|g' \
		-e 's|@NAGVIS_PATH@|${WWWDIR}|g' \
		${WRKSRC}/etc/apache2-nagvis.conf-sample
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/nagvis/|${WWWDIR}/|' \
		${WRKSRC}/etc/nagvis.ini.php-sample

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}/
	${MKDIR} ${STAGEDIR}${WWWDIR}/etc/automaps \
		${STAGEDIR}${WWWDIR}/share/var \
		${STAGEDIR}${WWWDIR}/var/tmpl/cache \
		${STAGEDIR}${WWWDIR}/var/tmpl/compile

.include <bsd.port.mk>
