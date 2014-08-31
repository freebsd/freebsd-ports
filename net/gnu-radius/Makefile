# Created by: lance@evitel.net
# $FreeBSD$

PORTNAME=	gnu-radius
PORTVERSION=	1.6.1
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	radius
DISTNAME=	radius-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GNU RADIUS server

CONFLICTS=	freeradius-0.* openradius-0.* radiusd-cistron-1.*
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_RC_SUBR=	radiusd
USE_SUBMAKE=	yes
USE_AUTOTOOLS=	libltdl
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}
DATADIR=	${PREFIX}/share/radius

INFO=		radius

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR="${.CURDIR}" \
		MKDIR="${MKDIR}"
CONFIGURE_ARGS+=--with-include-path="${LOCALBASE}/include/" \
		--with-lib-path="${LOCALBASE}/lib/"

OPTIONS_DEFINE=	CLIENT EXAMPLES DBM MYSQL PGSQL SNMP EMACS PAM
OPTIONS_DEFAULT=MYSQL
CLIENT_DESC=	Build client
EMACS_DESC=	Install Emacs dotfiles

EXAMPLE_FILES=	README ascend.rw c3620.rw cisco.rw comos.rw config.syntax \
		filter.rw hints-0.96 jetstream.rw nt.rw pam.conf radius.php

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900007
EXTRA_PATCHES=	${FILESDIR}/extra-utmpx
.endif

.if ${PORT_OPTIONS:MSNMP}
CONFIGURE_ARGS+=--enable-snmp
.endif

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS+=	libguile.so:${PORTSDIR}/lang/guile
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

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for ex_file in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${ex_file} ${STAGEDIR}${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.mk>
