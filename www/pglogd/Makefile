# New ports collection makefile for: pglogd
# Date created: 	23 April 2003
# Whom:			Allie Micka <allie@pajunas.com>
#
# $FreeBSD$
#

PORTNAME=	pglogd
PORTVERSION=	2.2b
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	http://www.digitalstratum.com/pglogd/
DISTNAME=	pglogd-2.2beta

MAINTAINER=	allie@pajunas.com
COMMENT=	Sends web server log entries to a PostgreSQL database

LIB_DEPENDS=	pq.3:${PORTSDIR}/databases/postgresql7

USE_REINPLACE=	yes

post-extract:
	@${CP} ${FILESDIR}/020.pglogd.sh ${WRKSRC}/020.pglogd.sh
	@${REINPLACE_CMD} -e "s=%%PREFIX%%=${PREFIX}=g" ${WRKSRC}/020.pglogd.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/020.pglogd.sh ${PREFIX}/etc/rc.d/020.pglogd.sh
	@if [ ! -f ${PREFIX}/etc/rc.d/020.pglogd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/020.pglogd.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/020.pglogd.sh ${PREFIX}/etc/rc.d/020.pglogd.sh; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
