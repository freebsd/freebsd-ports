# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	piwik
PORTVERSION=	1.10.1
CATEGORIES=	www
MASTER_SITES=	http://builds.piwik.org/

MAINTAINER=	hans@nordhaug.priv.no
COMMENT=	Open Source Web Analytics Software Program

LICENSE=	GPLv3

NO_BUILD=	yes
SUB_FILES=	pkg-message
USE_PHP=	dom gd iconv json session xml zlib
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	PHPPDOMYSQL PHPMYSQLI
PHPPDOMYSQL_DESC=	Use pdo_mysql php module
PHPMYSQLI_DESC=	Use mysqli php module

OPTIONS_DEFAULT=	PHPPDOMYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHPMYSQLI}
USE_PHP+=	mysqli
.endif
.if ${PORT_OPTIONS:MPHPPDOMYSQL}
USE_PHP+=	pdo_mysql
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${LOCALBASE}/bin/python|' \
		${WRKSRC}/misc/log-analytics/import_logs.py
	@${RM} ${WRKSRC}/misc/log-analytics/import_logs.py.bak

pre-install:
	@if [ ! -f ${LOCALBASE}/bin/php ]; then \
		echo " It seems you installed php without CLI enabled. "; \
		echo " This will cause problems when using piwik. "; \
		echo " If you want to reconsider, press Ctrl-C now to cancel. "; \
		echo " Then reinstall php with CLI enabled. "; \
		sleep 3; \
	fi

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
