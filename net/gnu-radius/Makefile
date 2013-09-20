# Created by: lance@evitel.net
# $FreeBSD$

PORTNAME=	gnu-radius
PORTVERSION=	1.6.1
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	radius
DISTNAME=	radius-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GNU RADIUS server

CONFLICTS=	freeradius-0.* openradius-0.* radiusd-cistron-1.*
USE_RC_SUBR=	radiusd
USE_SUBMAKE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

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

OPTIONS_DEFINE=	CLIENT DBM MYSQL PGSQL SNMP EMACS PAM
OPTIONS_DEFAULT=MYSQL
CLIENT_DESC=	Build client
EMACS_DESC=	Install Emacs dotfiles

CONFIG_FILES=	access.deny client.conf clients config dictionary \
		hints huntgroups naslist nastypes realms \
		sqlserver users
EXAMPLE_FILES=	README ascend.rw c3620.rw cisco.rw comos.rw config.syntax \
		filter.rw hints-0.96 jetstream.rw nt.rw pam.conf radius.php

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900007
EXTRA_PATCHES=	${FILESDIR}/extra-utmpx
.endif

.if ${PORT_OPTIONS:MSNMP}
CONFIGURE_ARGS+=--enable-snmp
.endif

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS+=	guile.21:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=--enable-client
PLIST_SUB+=	CLIENT=""
.else
CONFIGURE_ARGS+=--without-guile
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	MODULES=""
.else
PLIST_SUB+=	MODULES="@comment "
.endif

.if ${PORT_OPTIONS:MDBM}
CONFIGURE_ARGS+=--enable-dbm=ndbm
.endif

.if ${PORT_OPTIONS:MEMACS}
.include "${PORTSDIR}/Mk/bsd.emacs.mk"
USE_EMACS=	yes
CONFIGURE_ARGS+=--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}
PLIST_SUB+=	EMACS=""
.else
CONFIGURE_ARGS+=--without-lispdir
PLIST_SUB+=	EMACS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--enable-pam
.endif

post-patch:
	${REINPLACE_CMD} -e 's|extern unsigned scheme_gc_interval;||g' \
		${WRKSRC}/include/radiusd.h
	${REINPLACE_CMD} -e 's|int getline|ssize_t getline|' \
	    ${WRKSRC}/radtest/input.l ${WRKSRC}/radtest/input.c
	${REINPLACE_CMD}  -e '889s,], || 1 ],' ${WRKSRC}/raddb/Makefile.in

post-install:
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

.include <bsd.port.mk>
