# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freeradius
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	brian@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet --with-logdir=/var/log

MAN1=		radclient.1 radlast.1 radtest.1 raduse.1 radwho.1 radzap.1
MAN5=		acct_users.5 clients.5 dictionary.5 naslist.5 radiusd.conf.5 \
		users.5
MAN8=		builddbm.8 radiusd.8 radwatch.8

RADDB=		acct_users attrs clients clients.conf dictionary \
		dictionary.acc dictionary.aptis dictionary.ascend \
		dictionary.bay dictionary.cisco dictionary.compat \
		dictionary.erx dictionary.foundry dictionary.freeradius \
		dictionary.livingston dictionary.microsoft dictionary.nomadix \
		dictionary.quintum dictionary.redback dictionary.shasta \
		dictionary.shiva dictionary.tunnel dictionary.usr \
		dictionary.versanet hints huntgroups ldap.attrmap naslist \
		naspasswd postgresql.conf proxy.conf radiusd.conf realms \
		snmp.conf sql.conf users x99.conf

post-install:
	@${MKDIR} ${PREFIX}/etc/raddb
.for db in ${RADDB}
	${INSTALL_DATA} ${WRKSRC}/raddb/${db} ${PREFIX}/etc/raddb/${db}.sample
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/radiusd.sh ${PREFIX}/etc/rc.d/radiusd.sh

.include <bsd.port.mk>
