# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freeradius
PORTVERSION=	0.8.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	brian@FreeBSD.org
COMMENT=	A free RADIUS server implementation

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

BROKEN=         "Incorrect pkg-plist"

LOGDIR?=	/var/log

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --quiet --with-logdir=${LOGDIR}
INSTALLS_SHLIB=	yes

MAN1=		radclient.1 radlast.1 radtest.1 raduse.1 radwho.1 radzap.1
MAN5=		acct_users.5 clients.5 dictionary.5 naslist.5 radiusd.conf.5 \
		users.5
MAN8=		builddbm.8 radiusd.8 radrelay.8 radwatch.8

RADDB=		acct_users attrs clients clients.conf dictionary \
		dictionary.acc dictionary.alcatel dictionary.alteon \
	       	dictionary.altiga dictionary.aptis dictionary.ascend \
	       	dictionary.bay dictionary.cisco dictionary.cisco.bbsm \
		dictionary.cisco.vpn3000 dictionary.cisco.vpn5000 \
		dictionary.colubris dictionary.columbia_university \
	       	dictionary.compat dictionary.erx dictionary.foundry \
	       	dictionary.freeradius dictionary.juniper \
	       	dictionary.livingston dictionary.microsoft \
	       	dictionary.nomadix dictionary.quintum dictionary.redback \
	       	dictionary.shasta dictionary.shiva dictionary.tunnel \
	       	dictionary.usr dictionary.versanet hints huntgroups \
		ldap.attrmap mssql.conf naslist naspasswd oraclesql.conf \
	       	postgresql.conf  preproxy_users proxy.conf radiusd.conf \
	       	realms snmp.conf sql.conf users x99.conf x99passwd.sample

post-install:
	@${MKDIR} ${PREFIX}/etc/raddb
.for db in ${RADDB}
	${INSTALL_DATA} ${WRKSRC}/raddb/${db} ${PREFIX}/etc/raddb/${db}.sample
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/radiusd.sh ${PREFIX}/etc/rc.d/radiusd.sh

.include <bsd.port.mk>
