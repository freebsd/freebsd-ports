# New ports collection makefile for:	dhid
# Date created:		Sat Aug 21 06:13:59 EDT 1999
# Whom:			Oryx Gazella <oryx@ungulate.net>
#
# $FreeBSD$
#

PORTNAME=		dhid
PORTVERSION=		3.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=		oryx@ungulate.net

MAN8=			dhid.8

post-patch:
	@${ECHO} "===>   Patching dhid.h"
	${PERL} -i -p -e "s^__PREFIX__^${PREFIX}^g" ${WRKSRC}/dhid.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dhid.8 ${PREFIX}/man/man8
	${INSTALL} ${COPY} -o root -g wheel -m 600 ${WRKSRC}/dhid.conf ${PREFIX}/etc/dhid.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/dhid.sh ]; then \
		${ECHO} "===>   Installing ${PREFIX}/etc/rc.d/dhid.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/dhid.sh; \
		${ECHO} "[ -x \"${PREFIX}/sbin/dhid\" -a -f \"${PREFIX}/etc/dhid.conf\" ] && ${PREFIX}/sbin/dhid > /dev/null && ${ECHO} -n ' dhid'" >> ${PREFIX}/etc/rc.d/dhid.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/dhid.sh; \
	fi;
	@${ECHO} "--------------------------------------------------------------------------"
	@${ECHO} "Before dhid can run, you will need to register with a DHIS provider."
	@${ECHO} "See http://www.dhis.org/dhis/services/ for a list of providers."
	@${ECHO} "Enter the DHIS account information into the ${PREFIX}/etc/dhid.conf file."
	@${ECHO} "--------------------------------------------------------------------------"

.include <bsd.port.mk>
