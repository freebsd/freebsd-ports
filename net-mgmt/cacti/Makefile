# New ports collection makefile for:	cacti
# Date created:		6 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cacti
PORTVERSION=	0.8.6c
CATEGORIES=	net
MASTER_SITES=	http://www.cacti.net/downloads/

MAINTAINER=	so14k@so14k.com
COMMENT=	Web-driven graphing interface for RRDTool

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		net-snmp-config:${PORTSDIR}/net-mgmt/net-snmp

USE_MYSQL=	yes
USE_PHP=	mysql pcre session xml
WANT_PHP_WEB=	yes
WANT_PHP_CLI=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

CACTIDIR?=	share/cacti
CACTIUSER?=	cacti
CACTIGROUP?=	${CACTIUSER}
PLIST_SUB+=	CACTIDIR=${CACTIDIR}

post-extract:
	@${RM} -rf ${WRKSRC}/cactid/.deps

post-patch:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%LOCALBASE%%|${LOCALBASE}| ; \
		s|%%CACTIDIR%%|${CACTIDIR}| ; \
		s|%%CACTIUSER%%|${CACTIUSER}|' > ${PKGMESSAGE}

pre-install:
	@PREFIX=${PREFIX} CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} CACTIGROUP=${CACTIGROUP} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/${CACTIDIR}/
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${CACTIDIR}/

post-install:
	@PREFIX=${PREFIX} CACTIDIR=${CACTIDIR} CACTIUSER=${CACTIUSER} CACTIGROUP=${CACTIGROUP} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
