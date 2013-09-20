# Created by: osa
# $FreeBSD$

PORTNAME=	oops
PORTVERSION=	${OOPSVERSION}
PORTREVISION=	12
CATEGORIES=	www
MASTER_SITES=	http://oops-cache.org/ \
		ftp://kucha.ru/pub/misc/oops/

MAINTAINER=	marck@FreeBSD.org
COMMENT=	A caching web proxy server

BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk

OOPSVERSION=	1.5.24

USE_SUBMAKE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS?=--sbindir=${PREFIX}/sbin \
		--sysconfdir=${PREFIX}/etc/oops \
		--localstatedir=${OOPSVAR} \
		--libdir=${PREFIX}/libexec/oops \
		--enable-oops-user=${USERS} \
		--enable-large-files \
		--with-regexp=system
CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

.if ${CC} == "clang" || ${CXX} == "clang++"
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-configure.in \
		${PATCHDIR}/extra-patch-src_modules_Makefile.in
.endif

USERS=		oops
GROUPS=		nobody

OOPSVAR=	/var/run/oops
OOPSLOG=	/var/log/oops
.if !defined(NO_INSTALL_MANPAGES)
MAN8=		oops.8 oopsctl.8
.endif

USE_RC_SUBR=	oops
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

OPTIONS_DEFINE= MYSQL PGSQL PCRE
OPTIONS_RADIO=	DB
OPTIONS_RADIO_DB=	GIGABASE DB4
DB_DESC=	DB storage
OPTIONS_DEFAULT=	GIGABASE
GIGABASE_DESC=	GigaBase storage
DB4_DESC=	Berkeley DB v4 storage
MYSQL_DESC=	MySQL auth support
PGSQL_DESC=	PostgreSQL auth support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGIGABASE}
LIB_DEPENDS+=	gigabase_r.2:${PORTSDIR}/databases/gigabase
CONFIGURE_ARGS+=	--without-DB
.endif

.if ${PORT_OPTIONS:MDB4}
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=	--without-GB
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	YES
CONFIGURE_ARGS+=	--with-MYSQL=${PREFIX}
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	YES
CONFIGURE_ARGS+=	--with-PGSQL=${PREFIX}/pgsql
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-regexp=pcre
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTOHEADER}

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/man/man8
.endif
	@${MKDIR} -m 750 ${OOPSVAR}
	@${CHOWN} oops ${OOPSVAR}
	@${MKDIR} -m 750 ${OOPSLOG}
	@${CHOWN} oops ${OOPSLOG}
	${INSTALL_SCRIPT} ${WRKDIR}/oops ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
