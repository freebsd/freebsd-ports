# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freeradius
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free RADIUS server implementation

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		ltdl.4:${PORTSDIR}/devel/libltdl

LOGDIR?=	/var/log

CONFLICTS=	gnu-radius-1.* openradius-0.* radiusd-cistron-1.*
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --quiet --with-logdir=${LOGDIR} \
		--localstatedir=/var \
		--disable-ltdl-install \
		--with-ltdl-include=${LOCALBASE}/include \
		--with-ltdl-lib=${LOCALBASE}/lib \
		--with-large-files
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=	YES
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-rlm_ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL) || defined(WITH_POSTGRESQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7-client
PLIST_SUB+=	PGSQL=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_postgresql
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=		NOPORTDOCS=yes
.endif

# rlm_x99_token seems broken
CONFIGURE_ARGS+=--without-rlm_x99_token
PLIST_SUB+=	TOKEN="@comment "

INSTALLS_SHLIB=	yes

MAN1=		radclient.1 radlast.1 radtest.1 radwho.1 radzap.1
MAN5=		acct_users.5 clients.5 dictionary.5 naslist.5 radiusd.conf.5 \
		users.5
MAN8=		radiusd.8 radrelay.8 radwatch.8 rlm_ippool_tool.8

DICTS=		dictionary.acc dictionary.alcatel dictionary.alteon \
	       	dictionary.altiga dictionary.aptis dictionary.ascend \
	       	dictionary.bay dictionary.cisco dictionary.cisco.bbsm \
		dictionary.cisco.vpn3000 dictionary.cisco.vpn5000 \
		dictionary.colubris dictionary.columbia_university \
	       	dictionary.compat dictionary.erx dictionary.foundry \
	       	dictionary.freeradius dictionary.juniper \
	       	dictionary.livingston dictionary.microsoft \
	       	dictionary.nomadix dictionary.quintum dictionary.redback \
	       	dictionary.shasta dictionary.shiva dictionary.tunnel \
	       	dictionary.usr dictionary.versanet

post-install:
	@${MKDIR} ${PREFIX}/etc/raddb ${DATADIR}
.for dict in ${DICTS}
	${INSTALL_DATA} ${WRKSRC}/share/${dict} ${DATADIR}/${dict}
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/radiusd.sh ${PREFIX}/etc/rc.d/radiusd.sh

.include <bsd.port.mk>
