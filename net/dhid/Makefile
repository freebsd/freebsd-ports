# New ports collection makefile for:	dhid
# Version required:	3.0
# Date created:		Sat Aug 21 06:13:59 EDT 1999
# Whom:			Oryx Gazella <oryx@ungulate.net>
#
# $FreeBSD$
#

DISTNAME=		dhid-3.0
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=		oryx@ungulate.net

MAN1=			dtool.1
MAN8=			dhid.8

post-patch:
	@${ECHO} "===>   Patching dtool script and dhid.h"
	${PERL} -i -p -e "s^__PREFIX__^${PREFIX}^g" ${WRKSRC}/dtool
	${PERL} -i -p -e "s^__PREFIX__^${PREFIX}^g" ${WRKSRC}/dhid.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/dtool ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dhid.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/dtool.1 ${PREFIX}/man/man1
	${INSTALL} ${COPY} -o root -g wheel -m 600 ${WRKSRC}/dhid.conf ${PREFIX}/etc

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/dhid.sh ]; then \
		${ECHO} "===>   Installing ${PREFIX}/etc/rc.d/dhid.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/dhid.sh; \
		${ECHO} "[ -x ${PREFIX}/bin/dtool ] && ${PREFIX}/bin/dtool -s > /dev/null && echo -n ' dhid'" >> ${PREFIX}/etc/rc.d/dhid.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/dhid.sh; \
	fi

.include <bsd.port.mk>
