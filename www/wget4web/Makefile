# New ports collection makefile for:	wget4web
# Date created:				Feb 02, 2005
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$

PORTNAME=	wget4web
PORTVERSION=	1.0
CATEGORIES=	www ftp
MASTER_SITES=	http://irodov.nm.ru/wget4web/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	sam@brj.pp.ru
COMMENT=	WWW interface for console wget

USE_APACHE=	yes
RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}
# These are tunable
WEBOWN?=	www
WEBGRP?=	www
LOGSDIR?=	/var/log/wget4web
TASKDIR?=	/var/spool/wget4web
FILESDIR?=	/var/spool/wget4web/files
APACHEDIR?=	${PREFIX}/www/data

INSTALLDIR=	${APACHEDIR}/wget4web
NO_BUILD=	yes

PLIST_SUB=	INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,} \
		LOGSDIR=${LOGSDIR} TASKDIR=${TASKDIR} FILESDIR=${FILESDIR}

post-patch:
	@${REINPLACE_CMD} -e "s#%%LOGSDIR%%#${LOGSDIR}#; \
			     s#%%TASKDIR%%#${TASKDIR}#; \
			     s#%%FILESDIR%%#${FILESDIR}#" \
		${WRKSRC}/data/info.cgi

do-install:
	@${MKDIR} ${INSTALLDIR}; \
	cd ${WRKSRC}; ${FIND} . -name "*.cgi" -o -name "*.lib" \
		| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}; \
	${MKDIR} -p ${LOGSDIR} ${TASKDIR} ${FILESDIR}; \
	${CHOWN} ${WEBOWN}:${WEBGRP} ${LOGSDIR} ${TASKDIR} ${FILESDIR}

.include <bsd.port.mk>
