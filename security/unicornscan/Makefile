# Created by: Jon Passki <cykyc@yahoo.com>
# $FreeBSD$

PORTNAME=	unicornscan
PORTVERSION=	0.4.2
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF/osace/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asynchronous TCP and UDP port scanner

LICENSE=	GPLv2

LIB_DEPENDS=	libnet.so:net/libnet

USES=		gmake
CFLAGS+=	-DWITH_LONGOPTS

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/etc|' \
		${WRKSRC}/fconf/unicorn.conf
# Unbreak the build against Clang (it does not like one function being inline)
	@${REINPLACE_CMD} -e 's|^inline void nop|void nop|' \
		${WRKSRC}/src/unilib/tsc.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/unicornscan
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unicornscan/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/unicornscan
	@${MKDIR} ${STAGEDIR}${PREFIX}/var/unicornscan
	${INSTALL_PROGRAM} ${WRKSRC}/src/unicornscan ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/fantaip ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/scan_progs/unisend \
		${STAGEDIR}${PREFIX}/libexec/unicornscan
	${INSTALL_PROGRAM} ${WRKSRC}/src/scan_progs/unilisten \
		${STAGEDIR}${PREFIX}/libexec/unicornscan
	for confs in ${WRKSRC}/fconf/*.conf; do \
		${INSTALL_DATA} $$confs ${STAGEDIR}${PREFIX}/etc/unicornscan/`basename $$confs`.sample ; \
	done
	${INSTALL_DATA} ${WRKSRC}/fconf/port-numbers \
		${STAGEDIR}${PREFIX}/share/unicornscan
	for mods in ${WRKSRC}/src/payload_modules/*.so; do \
		${INSTALL_PROGRAM} $$mods ${STAGEDIR}${PREFIX}/libexec/unicornscan/modules/ ; \
	done
	for mods in ${WRKSRC}/src/report_modules/shlibs/*.so; do \
		${INSTALL_PROGRAM} $$mods ${STAGEDIR}${PREFIX}/libexec/unicornscan/modules/ ; \
	done
	for pofs in p0f.fp p0fa.fp p0fr.fp; do \
		${INSTALL_DATA} ${WRKSRC}/src/report_modules/p0f/$$pofs ${STAGEDIR}${PREFIX}/share/unicornscan/ ; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/src/report_modules/shlibs/libp0f.so \
		${STAGEDIR}${PREFIX}/libexec/unicornscan/modules
	${INSTALL_MAN} ${WRKSRC}/docs/unicornscan.1 ${STAGEDIR}${MANPREFIX}/man/man1
# XXX: shouldn't these files below be installed as PORTDOCS?
	for files in README misc/UDP_PAYLOADS_NEEDED \
	TODO_BUGSTOFIX README.database; do \
		${INSTALL_DATA} ${WRKSRC}/$$files ${STAGEDIR}${PREFIX}/share/unicornscan/ ; \
	done

.include <bsd.port.mk>
