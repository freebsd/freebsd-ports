# New ports collection makefile for:	radiusd-cistron
# Version required:	cistron radiusd 1.5.4.2
# Date created:		19 Apr 1998
# Whom:			john@nlc.net.au
#
# $Id$
#

DISTNAME=	radiusd-cistron-1.5.4.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/radius/

MAINTAINER=	john@nlc.net.au

MAKEFILE=	Makefile.BSD

MAN5=		clients.5rad naslist.5rad
MAN8=		radiusd.8

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE}

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} install
	@${MKDIR} -m 700 ${PREFIX}/etc/raddb
	@${MKDIR} -m 700 /var/log/radacct
	${INSTALL_DATA} ${WRKSRC}/raddb/clients ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/dictionary ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/dictionary.ascend ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/dictionary.compat ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/dictionary.merit ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/hints ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/huntgroups ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/naslist ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/raddb/users ${PREFIX}/etc/raddb
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/COPYRIGHT ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/ChangeLog ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/INSTALL.OLD ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.pam ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.simul ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/COPYRIGHT ${PREFIX}/share/doc/radiusd-cistron
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/clients.5rad ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/naslist.5rad ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/radiusd.8 ${MANPREFIX}/man/man8

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/radiusd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/radiusd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/radiusd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/radiusd ] && ${PREFIX}/sbin/radiusd && echo -n ' radiusd'" >> ${PREFIX}/etc/rc.d/radiusd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/radiusd.sh; \
	fi

.include <bsd.port.mk>
