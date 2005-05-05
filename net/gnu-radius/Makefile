# New ports collection makefile for:	gnu-radius
# Date created:		13 Jul 2001
# Whom:			lance@evitel.net
#
# $FreeBSD$

PORTNAME=	gnu-radius
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	radius
DISTNAME=	radius-${PORTVERSION}

MAINTAINER=	lance@merlin.net.ua
COMMENT=	GNU RADIUS server

CONFLICTS=	freeradius-0.* openradius-0.* radiusd-cistron-1.*
USE_RC_SUBR=	yes
USE_SUBMAKE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
USE_GETTEXT=	yes
CONFIGURE_TARGET=	# empty

PLIST_SUB=	PORTVERSION=${PORTVERSION}
DATADIR=	${PREFIX}/share/radius

INFO=		radius
MAN1=		radgrep.1 radlast.1 raduse.1 radwho.1
MAN8=		builddbm.8 radctl.8 radiusd.8 radping.8 radzap.8
MANCOMPRESSED=	no

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR="${.CURDIR}" \
		MKDIR="${MKDIR}"
CONFIGURE_ARGS+=--with-include-path="${LOCALBASE}/include/" \
		--with-lib-path="${LOCALBASE}/lib/"

OPTIONS=	CLIENT "Enable build client" off \
		DBM "Enable DBM support" off \
		MYSQL "Enable MySQL support" on \
		POSTGRESQL "Enable PostgreSQL support" off \
		SNMP "Enable SNMP support" off \
		NOTIFY "Enable TTL notification" off \
		EMACS "Enable emacs dotfiles install" off

.include <bsd.port.pre.mk>

.if defined(WITH_SNMP)
CONFIGURE_ARGS+=	--enable-snmp
.endif

.if defined(WITH_CLIENT)
CONFIGURE_ARGS+=	--enable-client
WITH_GUILE=	yes
BUILD_DEPENDS+=	guile:${PORTSDIR}/lang/guile
PLIST_SUB+=	GUILE=""
PLIST_SUB+=	CLIENT=""
.else
CONFIGURE_ARGS+=	--without-guile
PLIST_SUB+=	GUILE="@comment "
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_POSTGRESQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgres
INCLUDE_PATH+=	${LOCALBASE}/include/pgsql/
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_DBM)
CONFIGURE_ARGS+=	--enable-dbm=ndbm
PLIST_SUB+=	DBM=""
.else
PLIST_SUB+=	DBM="@comment "
.endif

.if defined(WITH_NOTIFY)
CONFIGURE_ARGS+=	--enable-notify
.endif

.if defined(WITH_EMACS)
EMACS_PORT_NAME=	emacs20
.include "${PORTSDIR}/Mk/bsd.emacs.mk"
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}
PLIST_SUB+=	EMACS=""
.else
EXTRA_PATCHES+=		${FILESDIR}/extrapatch-emacs
CONFIGURE_ARGS+=	--without-lispdir
PLIST_SUB+=	EMACS="@comment "
.endif

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%RC_SUBR%%|${RC_SUBR}|g" \
		< ${FILESDIR}/radiusd.sh > ${WRKDIR}/radiusd.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/radiusd.sh ${PREFIX}/etc/rc.d/radiusd.sh

.include <bsd.port.post.mk>
