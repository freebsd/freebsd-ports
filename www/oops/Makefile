# New ports collection makefile for:	oops
# Date created:		15 August 2000
# Whom:			Sergey Osokin aka oZZ <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	oops
PORTVERSION=	${OOPSVERSION}
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://oops-cache.org/
DISTNAME=	${PORTNAME}-${OOPSVERSION}

MAINTAINER=	marck@FreeBSD.org
COMMENT=	A caching web proxy server

BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk

OOPSVERSION=	1.5.24

USE_SUBMAKE=	yes
USE_AUTOCONF_VER=	259
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

MAN8=		oops.8 oopsctl.8
OOPSVAR=	/var/run/oops
OOPSLOG=	/var/log/oops

SCRIPTS_ENV+=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

USE_RC_SUBR=	YES
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.if defined(BATCH)
LIB_DEPENDS+=	gigabase_r.2:${PORTSDIR}/databases/gigabase
CONFIGURE_ARGS+=	--without-DB
.endif

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.oops

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTOHEADER}

post-build:
	@${SED} -e 's=%%RC_SUBR%%=${RC_SUBR}=g;s=%%PREFIX%%=${PREFIX}=g' \
		${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}.sh

pre-install:
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/man/man8
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${MKDIR} -m 750 ${OOPSVAR}
	@${CHOWN} oops ${OOPSVAR}
	@${MKDIR} -m 750 ${OOPSLOG}
	@${CHOWN} oops ${OOPSLOG}
	${INSTALL_SCRIPT} ${WRKDIR}/oops.sh ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
