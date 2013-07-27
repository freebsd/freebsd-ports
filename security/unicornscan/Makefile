# Created by: Jon Passki <cykyc@yahoo.com>
# $FreeBSD$

PORTNAME=	unicornscan
PORTVERSION=	0.4.2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/osace/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	cykyc@yahoo.com
COMMENT=	Asynchronous TCP and UDP port scanner

LICENSE=	GPLv2

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

USES=		gmake
MAKE_ENV=	LIBNET_CONFIG="${LIBNET_CONFIG}"
CFLAGS+=	-DWITH_LONGOPTS
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

SUB_FILES=	pkg-message

MAN1=		unicornscan.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${WRKSRC}/src/scan_progs/Makefile ${WRKSRC}/src/tools/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/etc|' \
		${WRKSRC}/fconf/unicorn.conf
# Unbreak the build against Clang (it does not like one function being inline)
	@${REINPLACE_CMD} -e 's|^inline void nop|void nop|' \
		${WRKSRC}/src/unilib/tsc.c

do-install:
	@${MKDIR} ${PREFIX}/etc/unicornscan
	@${MKDIR} ${PREFIX}/libexec/unicornscan/modules
	@${MKDIR} ${PREFIX}/share/unicornscan
	@${MKDIR} ${PREFIX}/var/unicornscan
	${INSTALL_PROGRAM} ${WRKSRC}/src/unicornscan ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/fantaip ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/scan_progs/unisend \
		${PREFIX}/libexec/unicornscan
	${INSTALL_PROGRAM} ${WRKSRC}/src/scan_progs/unilisten \
		${PREFIX}/libexec/unicornscan
	for confs in ${WRKSRC}/fconf/*.conf; do \
		${INSTALL_DATA} $$confs ${PREFIX}/etc/unicornscan/`basename $$confs`.sample ; \
	done
	${INSTALL_DATA} ${WRKSRC}/fconf/port-numbers \
		${PREFIX}/share/unicornscan
	for mods in ${WRKSRC}/src/payload_modules/*.so; do \
		${INSTALL_PROGRAM} $$mods ${PREFIX}/libexec/unicornscan/modules/ ; \
	done
	for mods in ${WRKSRC}/src/report_modules/shlibs/*.so; do \
		${INSTALL_PROGRAM} $$mods ${PREFIX}/libexec/unicornscan/modules/ ; \
	done
	for pofs in p0f.fp p0fa.fp p0fr.fp; do \
		${INSTALL_DATA} ${WRKSRC}/src/report_modules/p0f/$$pofs ${PREFIX}/share/unicornscan/ ; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/src/report_modules/shlibs/libp0f.so \
		${PREFIX}/libexec/unicornscan/modules
	${INSTALL_MAN} ${WRKSRC}/docs/unicornscan.1 ${MANPREFIX}/man/man1
# XXX: shouldn't these files below be installed as PORTDOCS?
	for files in README misc/UDP_PAYLOADS_NEEDED \
	TODO_BUGSTOFIX README.database; do \
		${INSTALL_DATA} ${WRKSRC}/$$files ${MANPREFIX}/share/unicornscan/ ; \
	done
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
