#
# Ports collection makefile for:	wanpipe
# Date created:				Tue Jul 15 14:27:31 UTC 2008
# Whom:					Alex Feldman <al.feldman@sangoma.com>
#
# $FreeBSD$
#

PORTNAME=	wanpipe
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	misc net kld
MASTER_SITES=	ftp://ftp.sangoma.com/FreeBSD/wanpipe/ports/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	A FreeBSD Driver for Sangoma AFT/S51x Series Cards

ONLY_FOR_ARCHS=	i386 amd64
NO_PACKAGE=	Should be in sync with the kernel to work correctly

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
		LDFLAGS="-L${LOCALBASE}/lib"
CPPFLAGS=	-I${LOCALBASE}/include

KMODDIR=	/boot/modules
MAKE_ENV=	KMODDIR="${KMODDIR}" \
		MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION} \
		CXX="${CXX}"

PKGCONFIG=	${WRKSRC}/configure_port.sh
PKGPOSTINSTALL=	${WRKSRC}/postinstall_port.sh
PKGPOSTDEINSTALL=${WRKSRC}/post-deinstall
OPTIONS=	TDM_VOICE "Enable TDM Voice support" off	\
		WAN_PROTOCOL "Enable Wanpipe Protocol support" off

.include <bsd.port.pre.mk>

.if defined(WITH_TDM_VOICE)
EXTRACT_DEPENDS=${PORTSDIR}/misc/zaptel/work:${PORTSDIR}/misc/zaptel
RUN_DEPENDS=	pidof:${PORTSDIR}/sysutils/pidof
.endif

EXTRA_ARGS=	${PREFIX}

.if defined(WITH_TDM_VOICE)
EXTRA_ARGS+=	WITH_TDM_VOICE
.endif
.if defined(WITH_WAN_PROTOCOL)
EXTRA_ARGS+=	WITH_WAN_PROTOCOL
.endif

pre-everything::
	@if [ ! -f /usr/src/sys/Makefile ]; then \
	${ECHO_MSG} ">> The wanpipe port needs FreeBSD kernel source code to compile."; \
	${ECHO_MSG} ">> Please install FreeBSD kernel source code in /usr/src/sys."; \
	${FALSE}; \
	fi

do-configure:
	@${SH} ${PKGCONFIG} ${DISTNAME} do-configure ${WRKSRC} ${EXTRA_ARGS}

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/wanpipe ${LOCALBASE}/etc/rc.d/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/wancfg_legacy ${LOCALBASE}/sbin/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/wancfg_zaptel ${LOCALBASE}/sbin/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/wanpipe_cfgft1 ${LOCALBASE}/sbin/
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/wanrouter ${LOCALBASE}/sbin/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
