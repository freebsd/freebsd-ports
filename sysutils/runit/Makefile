# New ports collection makefile for:	runit
# Date created:		2003-06-20
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	runit
PORTVERSION=	1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://smarden.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A init scheme with service supervision

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
ALL_TARGET=	default

SERVICE_DIR?=	/var/service

MAN8=		chpst.8 runit-init.8 runit.8 runsv.8 runsvchdir.8 \
		runsvctrl.8 runsvdir.8 runsvstat.8 svlogd.8 \
		svwaitdown.8 svwaitup.8 utmpset.8
DOCS=		package/CHANGES package/COPYING package/README \
		package/THANKS doc/*.html
CONFIG=		etc/freebsd/1 etc/2 etc/freebsd/3 etc/freebsd/ctrlaltdel \
	 	etc/freebsd/getty-ttyv4/run etc/freebsd/getty-ttyv4/finish

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc

do-build:
	cd ${WRKSRC} && package/compile && package/check
	@${MKDIR} ${WRKDIR}/etc/getty-ttyv4
	@${SED} -e 's!%%PREFIX%%!${PREFIX}!' \
		-e 's!%%SERVICE_DIR%%!${SERVICE_DIR}!' \
		${FILESDIR}/runsvdir.sh.in > ${WRKDIR}/runsvdir.sh.sample
.for file in ${CONFIG}
	@${SED} -e 's!/etc/runit!${PREFIX}/etc/runit!g' \
		-e 's!/service!${SERVICE_DIR}!g' \
		-e 's!/usr/local!${PREFIX}!g' \
		${WRKSRC}/${file} > ${WRKDIR}/${file:S!freebsd/!!}.sample
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${MANPREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKDIR}/runsvdir.sh.sample ${PREFIX}/etc/rc.d
	@${MKDIR} ${PREFIX}/etc/runit/getty-ttyv4
	${INSTALL_SCRIPT} ${WRKDIR}/etc/[123c]* ${PREFIX}/etc/runit
	${INSTALL_SCRIPT} ${WRKDIR}/etc/getty-ttyv4/* \
		${PREFIX}/etc/runit/getty-ttyv4
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
