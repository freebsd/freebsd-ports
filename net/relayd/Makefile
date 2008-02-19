# New ports collection makefile for: relayd
# Date created:         5 Jun 2007
# Whom:                 Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	relayd
PORTVERSION=	4.2.20071221
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	OpenBSD Relay Daemon

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent

WRKSRC=		${WRKDIR}/tmp
MAN5=		relayd.conf.5
MAN8=		relayctl.8 relayd.8
USE_RC_SUBR=	relayd

CFLAGS+=	-I${PREFIX}/include

WRKSRCC=	${WRKDIR}/tmp/relayctl
WRKSRCD=	${WRKDIR}/tmp/relayd
_MAKE=		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS}
RUSER=		_relayd
RGROUP=		_relayd

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/relayctl ${WRKSRC}/
	${MV} ${WRKDIR}/relayd   ${WRKSRC}/

pre-build:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRCD}/relayd.h \
		${WRKSRCD}/relayd.conf.5 ${WRKSRCD}/relayd.8

do-build:
	(cd ${WRKSRCC}; ${_MAKE} ${ALL_TARGET})
	(cd ${WRKSRCD}; ${_MAKE} ${ALL_TARGET})

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} RUSER=${RUSER} RGROUP=${RGROUP} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	(cd ${WRKSRCC}; ${_MAKE} ${INSTALL_TARGET} install-man)
	(cd ${WRKSRCD}; ${_MAKE} ${INSTALL_TARGET} install-man)

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not compile
.endif

.if ${OSVERSION} < 502106
IGNORE=	is of no use for you because your system is too old and doesn't have pf
.endif
.if (${OSVERSION} < 700049) && !defined(I_KNOW_WHAT_I_AM_DOING)
IGNORE=	needs a patched kernel to work correctly (http://www.openbsd.org/cgi-bin/cvsweb/src/sys/net/pf_table.c.diff?r1=1.67&r2=1.68)
.endif

.include <bsd.port.post.mk>
