# New ports collection makefile for:	gnu-radius
# Date created:		13 Jul 2001
# Whom:			lance@evitel.net
#
# $FreeBSD$

PORTNAME=	gnu-radius
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	radius
DISTNAME=	radius-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GNU RADIUS server

CONFLICTS=	freeradius-0.* openradius-0.* radiusd-cistron-1.*
USE_RC_SUBR=	radiusd.sh
USE_SUBMAKE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl:22 libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}
SUB_FILES=	radiusd.sh
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
		EMACS "Enable emacs dotfiles install" off \
		PAM "Enable PAM support" off

CONFIG_FILES=	access.deny client.conf clients config dictionary \
		hints huntgroups naslist nastypes realms \
		sqlserver users
EXAMPLE_FILES=	README ascend.rw c3620.rw cisco.rw comos.rw config.syntax \
		filter.rw hints-0.96 jetstream.rw nt.rw pam.conf radius.php

.include <bsd.port.pre.mk>

.if defined(WITH_SNMP)
CONFIGURE_ARGS+=--enable-snmp
.endif

.if defined(WITH_CLIENT)
LIB_DEPENDS+=	guile.20:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=--enable-client
PLIST_SUB+=	CLIENT=""
.else
CONFIGURE_ARGS+=--without-guile
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_MYSQL) || defined(WITH_POSTGRESQL)
PLIST_SUB+=	MODULES=""
.else
PLIST_SUB+=	MODULES="@comment "
.endif

.if defined(WITH_DBM)
CONFIGURE_ARGS+=--enable-dbm=ndbm
.endif

.if defined(WITH_EMACS)
.include "${PORTSDIR}/Mk/bsd.emacs.mk"
USE_EMACS=	yes
CONFIGURE_ARGS+=--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}
PLIST_SUB+=	EMACS=""
.else
CONFIGURE_ARGS+=--without-lispdir
PLIST_SUB+=	EMACS="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=--enable-pam
.endif

post-patch:
	${REINPLACE_CMD} -e 's|extern unsigned scheme_gc_interval;||g' \
		${WRKSRC}/include/radiusd.h
	${REINPLACE_CMD} -e 's|int getline|ssize_t getline|' \
	    ${WRKSRC}/radtest/input.l ${WRKSRC}/radtest/input.c

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/radiusd.sh ${PREFIX}/etc/rc.d/radiusd.sh
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
. for ex_file in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${ex_file} ${EXAMPLESDIR}
. endfor
.endif
.for conf_file in ${CONFIG_FILES}
	@test -f ${PREFIX}/etc/raddb/${conf_file} || ${CP} -p \
	${PREFIX}/etc/raddb/${conf_file}-dist ${PREFIX}/etc/raddb/${conf_file}
.endfor

.include <bsd.port.post.mk>
