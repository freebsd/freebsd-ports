# New ports collection makefile for:	authpf
# Date created:		09 May 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	authpf
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	http://pf4freebsd.love2party.net/
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
PKGNAMESUFFIX=	-altq
.endif
DISTNAME=	pf_freebsd_${PORTVERSION}

MAINTAINER=	mlaier@freebsd.org
COMMENT=	Authentification shell for pf gateways

RUN_DEPENDS=	${LOCALBASE}/modules/pf.ko:${PORTSDIR}/security/pf
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
RUN_DEPENDS+=	${LOCALBASE}/modules/pfaltq.ko:${PORTSDIR}/security/pf
.endif

WRKSRC=		${WRKDIR}/pf_freebsd_${PORTVERSION}

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE= yes
.endif

MAN8=		authpf.8

MANCOMPRESSED=	maybe

MAKE_ARGS=	MANDIR="${PREFIX}/man/man" ONLY_AUTHPF=yes

SRC_BASE?=	/usr/src
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
SYS_ALTQ?=	${SRC_BASE}/sys.altq
MAKE_ARGS+=	WITH_ALTQ="yes" SYS_ALTQ="${SYS_ALTQ}"
PLIST_SUB+=	WITH_ALTQ=""
.else
PLIST_SUB+=	WITH_ALTQ="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Only for 5.0 and above"
.endif

.if ${OSVERSION} > 502104
IGNORE=		"authpf is part of the base system now"
.endif

.if !exists(${SRC_BASE}/sys/Makefile) && \
    (defined(WITH_ALTQ) && !exists(${SYS_ALTQ}/Makefile))
IGNORE=		"Kernel source files required"
.endif

.if !defined(WITH_ALTQ) || (${WITH_ALTQ} != "yes")
pre-fetch:
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD} "* If you have ALTQ support from:                      *"
	@${ECHO_CMD} "*   http://www.nipsi.de/altq/index.html               *"
	@${ECHO_CMD} "* You can may define WITH_ALTQ=yes to make use of it  *"
	@${ECHO_CMD} "* Please define SYS_ALTQ to point to the patched src  *"
	@${ECHO_CMD} "*                                                     *"
	@${ECHO_CMD} "* e.g.: make WITH_ALTQ=yes SYS_ALTQ=/usr/src/sys.altq *"
	@${ECHO_CMD} "*                                                     *"
	@${ECHO_CMD} "======================================================="
	@sleep 2
.endif

post-patch:
	${SED} -e 's!%%PREFIX%%!${PREFIX}!' ${PATCHDIR}/pathnames.h.sed > \
	${WRKSRC}/authpf/pathnames.h

pre-su-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
	${MKDIR} ${PREFIX}/etc/authpf
	${MKDIR} ${PREFIX}/etc/authpf/users
	${MKDIR} ${PREFIX}/etc/authpf/banned
	${SED} -e 's!%%PREFIX%%!${PREFIX}!' ${PKGMESSAGE}

.include <bsd.port.post.mk>
