# Ports collection makefile for:  jffnms
# Date created:			  Aug 21 2003
# Whom:				  Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	jffnms
PORTVERSION=	0.7.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	asa@gascom.ru
COMMENT=	Very advanced network monitoring and control system

RUN_DEPENDS=	neato:${PORTSDIR}/graphics/graphviz \
		rrdtool:${PORTSDIR}/net/rrdtool \
		php:${PORTSDIR}/lang/php4-nms \
		nmap:${PORTSDIR}/security/nmap \
		tmpwatch:${PORTSDIR}/sysutils/tmpwatch

USE_MYSQL=	yes
USE_REINPLACE=	yes

JFFNMSDIR?=	share/jffnms
PHPSO?=		${LOCALBASE}/libexec/apache/libphp4.so
LDD?=		/usr/bin/ldd
CRONTAB?=	/usr/bin/crontab

PLIST_SUB=	JFFNMSDIR=${JFFNMSDIR}

do-build:
	@${REINPLACE_CMD} -e 's|/opt/jffnms|${LOCALBASE}/${JFFNMSDIR}|g' \
		-e 's|/usr/bin/php|${LOCALBASE}/bin/php|g' \
		-e 's|/usr/bin/rrdtool|${LOCALBASE}/bin/rrdtool|g' \
		-e 's|/usr/bin/nmap|${LOCALBASE}/bin/nmap|g' \
		-e 's|/usr/bin/neato|${LOCALBASE}/bin/neato|g' \
		-e 's| /jffnms| /htdocs|g' \
		${WRKSRC}/conf/config.ini

do-install:
	@${MKDIR} ${LOCALBASE}/${JFFNMSDIR}
	@${CP} -R ${WRKSRC}/* ${LOCALBASE}/${JFFNMSDIR}
	@${CHOWN} -R www:www ${LOCALBASE}/${JFFNMSDIR}
	@${SED} -e 's|%LOCALBASE%|${LOCALBASE}|g' \
		-e 's|%JFFNMSDIR%|${LOCALBASE}/${JFFNMSDIR}|g' ${FILESDIR}/jffnms.cron \
		> ${LOCALBASE}/${JFFNMSDIR}/jffnms.cron
	@${SED} -e 's|%JFFNMSDIR%|${LOCALBASE}/${JFFNMSDIR}|g' \
		-e 's|%JFFNMS%|${DISTNAME}|g' ${FILESDIR}/jffnms_db.sh \
		> ${LOCALBASE}/${JFFNMSDIR}/jffnms_db.sh
	@${CRONTAB} -u www ${LOCALBASE}/${JFFNMSDIR}/jffnms.cron
	@${SED} -e 's|%JFFNMSDIR%|${LOCALBASE}/${JFFNMSDIR}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
