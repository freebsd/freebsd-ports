# New ports collection makefile for:	dhid
# Date created:		Sat Aug 21 06:13:59 EDT 1999
# Whom:			Oryx Gazella <oryx@ungulate.net>
#
# $FreeBSD$
#

PORTNAME=		dhid
PORTVERSION=		4.0.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.dhis.org/pub/dhis/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${PORTNAME}-3.1${EXTRACT_SUFX}

MAINTAINER=		oryx@ungulate.net

OLDWRKSRC=		${WRKDIR}/${PORTNAME}-3.1

MAN8=			dhid.8

post-patch:
	@${ECHO} "===>   Patching dhid.h"
	${PERL} -i -p -e "s^__PREFIX__^${PREFIX}^g" ${WRKSRC}/dhid.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	${INSTALL_MAN} ${OLDWRKSRC}/dhid.8 ${PREFIX}/man/man8
	${INSTALL} ${COPY} -o root -g wheel -m 600 ${OLDWRKSRC}/dhid.conf ${PREFIX}/etc/dhid.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/dhid.sh ]; then \
		${ECHO} "===>   Installing ${PREFIX}/etc/rc.d/dhid.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/dhid.sh ${PREFIX}/etc/rc.d/dhid.sh; \
	fi;
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
