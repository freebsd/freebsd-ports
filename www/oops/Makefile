# New ports collection makefile for:	oops
# Date created:		15 August 2000
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	oops
PORTVERSION=	1.5.22
CATEGORIES=	www
MASTER_SITES=	http://zipper.paco.net/~igor/oops/

MAINTAINER=	ozz@FreeBSD.org.ru

GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--sbindir=${PREFIX}/sbin \
		--sysconfdir=${PREFIX}/etc/oops \
		--localstatedir=${OOPSVAR} \
		--libdir=${PREFIX}/libexec/oops \
		--enable-oops-user=oops \
		--enable-large-files

MAN8=		oops.8 oopsctl.8
OOPSVAR=	/var/run/oops

SCRIPTS_ENV+=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.oops

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/man/man8
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Sample of configuration file placed at ${PREFIX}/etc/oops !"
	@ ${ECHO} "Copy oops.cfg.sample to oops.cfg, then run server..."
	@ ${ECHO} "------------------------------------------------------------"
	@${MKDIR} ${OOPSVAR}
	@${CHMOD} 750 ${OOPSVAR}
	@${CHOWN} oops ${OOPSVAR}

	${ECHO} "Installing ${PREFIX}/etc/rc.d/oops.sh.sample startup file."
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/oops.sh ${PREFIX}/etc/rc.d/oops.sh.sample

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
