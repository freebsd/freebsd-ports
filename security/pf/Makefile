# New ports collection makefile for:	pf_freebsd
# Date created:		08 May 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	pf_freebsd
PORTVERSION=	2.03
CATEGORIES=	security ipv6
MASTER_SITES=	http://pf4freebsd.love2party.net/
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
PKGNAMESUFFIX=	-altq
.endif
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	max@love2party.net
COMMENT=	OpenBSD pf as a kldmodule

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE= yes
.endif

STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/pf.sh.sample
SAMPLE_CONFIG=  ${PREFIX}/etc/pf.conf.default
SAMPLE_PFOS=	${PREFIX}/etc/pf.os

MAN1=		pftcpdump.1
MAN4=		pf.4 pflog.4 pfsync.4
MAN5=		pf.conf.5 pf.os.5
MAN8=		ftp-proxy.8 pfctl.8 pflogd.8

MANCOMPRESSED=	maybe

KMODDIR?=	${PREFIX}/modules
MAKE_ARGS=	KMODDIR="${KMODDIR}" MANDIR="${PREFIX}/man/man"

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

.if !exists(${SRC_BASE}/sys/Makefile) && \
    (defined(WITH_ALTQ) && !exists(${SYS_ALTQ}/Makefile))
IGNORE=		"Kernel source files required"
.endif

.if !defined(WITH_ALTQ) || (${WITH_ALTQ} != "yes")
pre-fetch:
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "* If you have ALTQ support from:                      *"
	@${ECHO_MSG} "*   http://www.nipsi.de/altq/index.html          or   *"
	@${ECHO_MSG} "*   http://www.rofug.ro/projects/freebsd-altq/        *"
	@${ECHO_MSG} "* You can define WITH_ALTQ=yes to make use of it      *"
	@${ECHO_MSG} "* Please define SYS_ALTQ to point to the patched src  *"
	@${ECHO_MSG} "*                                                     *"
	@${ECHO_MSG} "* e.g.: make WITH_ALTQ=yes SYS_ALTQ=/usr/src/sys.altq *"
	@${ECHO_MSG} "*                                                     *"
	@${ECHO_MSG} "======================================================="
	@sleep 2
.endif

post-patch:
	@${CP} ${WRKSRC}/pfctl/pfctl_parser.h \
		${WRKSRC}/pfctl/pfctl_parser.h.orig
	@${SED} -e 's!%%PREFIX%%!${PREFIX}!' 		\
		${WRKSRC}/pfctl/pfctl_parser.h.orig > 	\
		${WRKSRC}/pfctl/pfctl_parser.h
pre-su-install:
	${MKDIR} ${KMODDIR}
	${MKDIR} ${PREFIX}/include/pf
	${MKDIR} ${PREFIX}/include/pf/net
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
	${MKDIR} ${PREFIX}/include/pf/altq
.endif
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
	${ECHO_MSG} "Installing include files ..."
	${INSTALL_DATA} ${WRKSRC}/include/net/pfvar.h 			\
		${PREFIX}/include/pf/net
	${INSTALL_DATA} ${WRKSRC}/include/net/if_pflog.h 		\
		${PREFIX}/include/pf/net
	${INSTALL_DATA} ${WRKSRC}/include/net/if_pfsync.h 		\
		${PREFIX}/include/pf/net
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
	${INSTALL_DATA} ${WRKSRC}/include/altq/*.h			\
		${PREFIX}/include/pf/altq
.endif
	@if [ -f ${WRKSRC}/man/pf.4.gz ]; then				\
		${ECHO_MSG} "Installing pftcpdump(1) man page.";	\
		${GZIP_CMD} -cn ${WRKSRC}/freebsd_tcpdump/tcpdump.1 >	\
			 ${WRKSRC}/freebsd_tcpdump/tcpdump.1.gz ;	\
		${INSTALL_MAN} ${WRKSRC}/freebsd_tcpdump/tcpdump.1.gz	\
			${PREFIX}/man/man1/pftcpdump.1.gz ;		\
	else								\
		${ECHO_MSG} "Installing pftcpdump(1) man page.";	\
		${INSTALL_MAN} ${WRKSRC}/freebsd_tcpdump/tcpdump.1	\
			${PREFIX}/man/man1/pftcpdump.1 ;		\
	fi
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO_MSG} "Installing ${STARTUP_SCRIPT} startup file." ; \
		${INSTALL_SCRIPT} ${FILESDIR}/pf.sh.sample		\
			${STARTUP_SCRIPT} ;				\
	fi
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${ECHO_MSG} "Installing ${SAMPLE_CONFIG} config file." ; \
		${INSTALL_DATA} ${FILESDIR}/pf.conf.default		\
			${SAMPLE_CONFIG};				\
	fi
	@if [ ! -f ${SAMPLE_PFOS} ]; then				\
		${ECHO_MSG} "Installing ${SAMPLE_PFOS} config file.";	\
		${INSTALL_DATA} ${FILESDIR}/pf.os.default		\
			${SAMPLE_PFOS};					\
	fi
	${SED} -e 's!%%PREFIX%%!${PREFIX}!' ${PKGMESSAGE}

.include <bsd.port.post.mk>
