# New ports collection makefile for:	radiusd-cistron
# Date created:		15 Jan 1999
# Whom:			john@nlc.net.au
#
# $FreeBSD$
#

PORTNAME=	radiusd-cistron
PORTVERSION=	1.6.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/radius/ \
		ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	john@nlc.net.au

MAKEFILE=	Makefile.BSD

MAN1=		radlast.1 radtest.1 raduse.1 radwho.1 radzap.1
MAN5=		clients.5rad naslist.5rad
MAN8=		radiusd.8 radwatch.8

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE}

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} install
	@${MKDIR} -m 700 /var/log/radacct
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.Cistron ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.Livingston ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/ChangeLog ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/INSTALL.OLD ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.Y2K ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.cisco ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.pam ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.proxy ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.simul ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.usersfile ${PREFIX}/share/doc/radiusd-cistron
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/radlast.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radtest.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/raduse.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radwho.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radzap.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/clients.5rad ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/naslist.5rad ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/radiusd.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/radwatch.8 ${MANPREFIX}/man/man8

post-install:
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" ${FILESDIR}/radiusd.sh.tmpl \
		> ${PREFIX}/etc/rc.d/radiusd.sh
	@${CHMOD} 555 ${PREFIX}/etc/rc.d/radiusd.sh
	@${CHOWN} root.wheel ${PREFIX}/etc/rc.d/radiusd.sh

.include <bsd.port.mk>
