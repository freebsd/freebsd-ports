# New ports collection makefile for:	oops
# Date created:		15 August 2000
# Whom:			Sergey Osokin aka oZZ <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	oops
PORTVERSION=	${OOPSVERSION}
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://oops-cache.org/ \
		ftp://kucha.ru/pub/misc/oops/
DISTNAME=	${PORTNAME}-${OOPSVERSION}

MAINTAINER=	marck@FreeBSD.org
COMMENT=	A caching web proxy server

BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk

OOPSVERSION=	1.5.24

USE_SUBMAKE=	yes
USE_AUTOTOOLS=	autoconf:261
CONFIGURE_ARGS?=--sbindir=${PREFIX}/sbin \
		--sysconfdir=${PREFIX}/etc/oops \
		--localstatedir=${OOPSVAR} \
		--libdir=${PREFIX}/libexec/oops \
		--enable-oops-user=oops \
		--enable-large-files
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC" \
		CXXFLAGS="${CXXFLAGS} -fPIC" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OOPSVAR=	/var/run/oops
OOPSLOG=	/var/log/oops
.if !defined(NO_INSTALL_MANPAGES)
MAN8=		oops.8 oopsctl.8
.endif

USE_RC_SUBR=	oops
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

OPTIONS=	GIGABASE	"GigaBase storage" on \
		DB4		"Berkeley DB v4 storage" off \
		MYSQL		"MySQL auth support" off \
		PGSQL		"PostgreSQL auth support" off \
		PCRE		"PCRE support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GIGABASE)
.if defined (WITH_DB4)
BROKEN=	Only one DB storage can be used (First)
.endif

LIB_DEPENDS+=	gigabase_r.2:${PORTSDIR}/databases/gigabase
CONFIGURE_ARGS+=	--without-DB
.endif

.if defined(WITH_DB4)
.if defined(WITHOUT_GIGABASE)
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=	--without-GB
.else
BROKEN=	Only one DB storage can be used
.endif
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
CONFIGURE_ARGS+=	--with-MYSQL=${PREFIX}
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	YES
CONFIGURE_ARGS+=	--with-PGSQL=${PREFIX}/pgsql
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-regexp=pcre
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTOHEADER}

pre-install:
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/man/man8
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${MKDIR} -m 750 ${OOPSVAR}
	@${CHOWN} oops ${OOPSVAR}
	@${MKDIR} -m 750 ${OOPSLOG}
	@${CHOWN} oops ${OOPSLOG}
	${INSTALL_SCRIPT} ${WRKDIR}/oops ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
