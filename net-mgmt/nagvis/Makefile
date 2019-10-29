# Created by: Andrew 'derfi' Sidorov <derfi@vei.ru>
# $FreeBSD$

PORTNAME=	nagvis
PORTVERSION=	1.9.16
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.nagvis.org/share/

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Visualization addon for Nagios

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext php:web
USE_PHP=	gd gettext mbstring session json pdo pdo_sqlite

NO_BUILD=	yes
NO_ARCH=	yes

SUB_LIST+=	WWW_OWNER=${WWW_OWNER} WWW_GROUP=${WWW_GROUP} \
		DIRMODE=${DIRMODE} FILEMODE=${FILEMODE}
SUB_FILES+=	pkg-install pkg-deinstall
PLIST_SUB+=	WWWDIR="${WWWDIR}"
WWW_OWNER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}
DIRMODE?=	750
FILEMODE?=	640

OPTIONS_DEFINE=		GRAPHVIZ
OPTIONS_SINGLE=		BROKER
OPTIONS_SINGLE_BROKER=	MKLIVESTATUS NDO2DB
OPTIONS_DEFAULT=	MKLIVESTATUS

GRAPHVIZ_DESC=		Graphviz is needed for automaps
MKLIVESTATUS_DESC=	Depend on mk-livestatus broker (preferred)
NDO2DB_DESC=		Depend on ndo2db broker

GRAPHVIZ_RUN_DEPENDS=		dot:graphics/graphviz
MKLIVESTATUS_RUN_DEPENDS=	mk-livestatus>=0:net-mgmt/mk-livestatus
NDO2DB_USE=			PHP=mysqli
NDO2DB_RUN_DEPENDS=		ndo2db:net-mgmt/ndoutils

post-extract:
	@${RM} ${WRKSRC}/.gitignore ${WRKSRC}/install.sh ${WRKSRC}/INSTALL

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|@NAGVIS_WEB@|/nagvis|g' \
		-e 's|@NAGVIS_PATH@|${WWWDIR}|g' \
		${WRKSRC}/etc/apache2-nagvis.conf-sample
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/nagvis/|${WWWDIR}/|' \
		${WRKSRC}/etc/nagvis.ini.php-sample

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/etc/automaps \
		${STAGEDIR}${WWWDIR}/share/var \
		${STAGEDIR}${WWWDIR}/var/tmpl/cache \
		${STAGEDIR}${WWWDIR}/var/tmpl/compile
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
