# New ports collection makefile for:  xtradius
# Date created:        06 September 2000
# Whom:                pal@paladin7.net
#
# $FreeBSD$
#

PORTNAME=	xtradius
PORTVERSION=	1.0b3
CATEGORIES=	net
MASTER_SITES=	http://www.xtradius.com/download/
DISTNAME=	xtradius-1.0beta3
EXTRACT_SUFX=	.tgz

MAINTAINER=	pal@paladin7.net

MAKEFILE=	Makefile.BSD

MAN1=		radlast.1 radtest.1 raduse.1 radwho.1 radzap.1
MAN5=		clients.5rad naslist.5rad
MAN8=		radiusd.8 radwatch.8
VARD=		/var/log

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE}

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} install
	@${MKDIR} -m 700 ${VARD}/radacct
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.Cistron ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.Livingston ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/ChangeLog ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/INSTALL.OLD ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/README.Y2K ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/README.cisco ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/README.pam ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/README.proxy ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/README.simul ${PREFIX}/share/doc/radiusd-xtradius
	${INSTALL_DATA} ${WRKSRC}/doc/README.usersfile ${PREFIX}/share/doc/radiusd-xtradius
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
	${INSTALL_DATA} ${WRKSRC}/contrib/pg_xtradius/users ${PREFIX}/etc/raddb/users.pg
	${INSTALL_DATA} ${WRKSRC}/contrib/pg_xtradius/pg_auth.pl ${PREFIX}/etc/raddb
	${INSTALL_DATA} ${WRKSRC}/contrib/pg_xtradius/pg_acct.pl ${PREFIX}/etc/raddb
	@${CHMOD} 555 ${PREFIX}/etc/raddb/pg_acct.pl ${PREFIX}/etc/raddb/pg_auth.pl
	@${CHOWN} root.wheel ${PREFIX}/etc/raddb/pg_acct.pl
	@${CHOWN} root.wheel ${PREFIX}/etc/raddb/pg_auth.pl
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" ${FILESDIR}/radiusd.sh.tmpl \
		> ${PREFIX}/etc/rc.d/radiusd.sh
	@${CHMOD} 555 ${PREFIX}/etc/rc.d/radiusd.sh
	@${CHOWN} root.wheel ${PREFIX}/etc/rc.d/radiusd.sh
.include <bsd.port.mk>
