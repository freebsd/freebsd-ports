# New ports collection makefile for:	radiusd-cistron
# Date created:		15 Jan 1999
# Whom:			john@nlc.net.au
#
# $FreeBSD$
#

PORTNAME=	radiusd-cistron
PORTVERSION=	1.6.7
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/radius/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A RADIUS-compliant remote authentication and accounting server

CONFLICTS?=	freeradius-0.* gnu-radius-1.* openradius-0.*
MAKEFILE=	Makefile.BSD
RADIUS_DIR=	${PREFIX}/etc/raddb
MAKE_ENV+=	RADIUS_DIR="${RADIUS_DIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		radclient.1 radlast.1 radtest.1 radwho.1 radzap.1
MAN5=		clients.5rad naslist.5rad
MAN8=		radiusd.8 radrelay.8 radwatch.8

DOCFILES=	COPYRIGHT INSTALL doc/ChangeLog doc/README doc/README.Y2K \
		doc/README.cisco doc/README.pam doc/README.proxy \
		doc/README.simul doc/README.usersfile

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE}

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} install
	${SED} -e "s=%%PREFIX%%=${PREFIX}=" \
		${FILESDIR}/radiusd-cistron.sh \
		> ${WRKSRC}/radiusd-cistron.sh
	${INSTALL_SCRIPT} ${WRKSRC}/radiusd-cistron.sh \
		${PREFIX}/etc/rc.d/radiusd-cistron.sh
	@${MKDIR} -m 700 /var/log/radacct
	${INSTALL_MAN} ${WRKSRC}/doc/radlast.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radtest.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radwho.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radzap.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/clients.5rad ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/naslist.5rad ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/radiusd.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/radwatch.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
