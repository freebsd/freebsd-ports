# Ports collection makefile for:  jffnms
# Date created:			  Aug 21 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	jffnms
PORTVERSION=	0.7.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	asa@gascom.ru
COMMENT=	Very advanced network monitoring and control system

RUN_DEPENDS=	neato:${PORTSDIR}/graphics/graphviz \
		rrdtool:${PORTSDIR}/net/rrdtool \
		php:${PORTSDIR}/lang/php4-nms \
		nmap:${PORTSDIR}/security/nmap \
		${LOCALBASE}/sbin/tmpwatch:${PORTSDIR}/sysutils/tmpwatch

USE_MYSQL=	yes
USE_REINPLACE=	yes

JFFNMSDIR?=	share/jffnms
CRONTAB?=	/usr/bin/crontab

PLIST_SUB=	JFFNMSDIR=${JFFNMSDIR}

do-build:
	@${REINPLACE_CMD} -e 's|/opt/jffnms|${PREFIX}/${JFFNMSDIR}|g' \
		-e 's|/usr/bin/php|${LOCALBASE}/bin/php|g' \
		-e 's|/usr/bin/rrdtool|${LOCALBASE}/bin/rrdtool|g' \
		-e 's|/usr/bin/nmap|${LOCALBASE}/bin/nmap|g' \
		-e 's|/usr/bin/neato|${LOCALBASE}/bin/neato|g' \
		-e 's| /jffnms| /htdocs|g' \
		${WRKSRC}/conf/config.ini

do-install:
	@-${RM} ${WRKSRC}/engine/tmpwatch.sh.orig > /dev/null 2>&1
	@${MKDIR} ${PREFIX}/${JFFNMSDIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${JFFNMSDIR}
	@${CHOWN} -R www:www ${PREFIX}/${JFFNMSDIR}
	@${SED} -e 's|%LOCALBASE%|${PREFIX}|g' \
		-e 's|%JFFNMSDIR%|${PREFIX}/${JFFNMSDIR}|g' ${FILESDIR}/jffnms.cron \
		> ${PREFIX}/${JFFNMSDIR}/jffnms.cron
	@${SED} -e 's|%JFFNMSDIR%|${PREFIX}/${JFFNMSDIR}|g' \
		-e 's|%JFFNMS%|${DISTNAME}|g' ${FILESDIR}/jffnms_db.sh \
		> ${PREFIX}/${JFFNMSDIR}/jffnms_db.sh
	@${CRONTAB} -u www ${PREFIX}/${JFFNMSDIR}/jffnms.cron
	@${SED} -e 's|%JFFNMSDIR%|${PREFIX}/${JFFNMSDIR}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
