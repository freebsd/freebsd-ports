# New ports collection makefile for:	unicornscan
# Date created:		4 October 2004
# Whom:			cykyc
#
# $FreeBSD$
#

PORTNAME=	unicornscan
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.dyadsecurity.com/unicornscan/

MAINTAINER=	cykyc@yahoo.com
COMMENT=	Next-generation of udpscan plus a high-speed TCP scanner

BUILD_DEPENDS=	${LOCALBASE}/include/libnet/libnet-types.h:${PORTSDIR}/net/libnet-devel

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		unicornscan.1

PKGMESSAGE=     ${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

# Check if where building on a 5.3 or older system. Older
# system require libpcap 0.8.x to be installed.

.if ${OSVERSION} < 503000
BUILD_DEPENDS+=	${PREFIX}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

# Systems newer then 502103 include the getopt_long
# function

.if ${OSVERSION} > 502103
CFLAGS+= -DWITH_LONGOPTS
.endif

post-patch:
.for text in pkg-message
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	${PKGDIR}/${text} >${WRKDIR}/${text}
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/unicornscan
	${MKDIR} ${PREFIX}/libexec/unicornscan/modules
	${MKDIR} ${PREFIX}/share/unicornscan
	${MKDIR} ${PREFIX}/var/unicornscan
	${INSTALL_PROGRAM} ${WRKSRC}/src/unicornscan ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/fantaip ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/scan_progs/unisend ${PREFIX}/libexec/unicornscan
	${INSTALL_PROGRAM} ${WRKSRC}/src/scan_progs/unilisten ${PREFIX}/libexec/unicornscan
	${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/etc|' \
		${WRKSRC}/fconf/unicorn.conf
	for confs in ${WRKSRC}/fconf/*.conf; do\
		${INSTALL_DATA} $$confs ${PREFIX}/etc/unicornscan/`basename $$confs`.sample ;\
	done
	${INSTALL_DATA} ${WRKSRC}/fconf/port-numbers ${PREFIX}/share/unicornscan
	for mods in ${WRKSRC}/src/payload_modules/*.so; do\
		${INSTALL_PROGRAM} $$mods ${PREFIX}/libexec/unicornscan/modules/ ;\
	done
	for mods in ${WRKSRC}/src/report_modules/shlibs/*.so; do\
		${INSTALL_PROGRAM} $$mods ${PREFIX}/libexec/unicornscan/modules/ ;\
	done
	for pofs in p0f.fp p0fa.fp p0fr.fp; do\
		${INSTALL_DATA} ${WRKSRC}/src/report_modules/p0f/$$pofs ${PREFIX}/share/unicornscan/ ;\
	done
	${INSTALL_PROGRAM} ${WRKSRC}/src/report_modules/shlibs/libp0f.so \
		${PREFIX}/libexec/unicornscan/modules/
	${INSTALL_MAN} ${WRKSRC}/docs/unicornscan.1 ${PREFIX}/man/man1/
	for files in LICENSE README misc/UDP_PAYLOADS_NEEDED \
	TODO_BUGSTOFIX README.database; do\
		${INSTALL_DATA} ${WRKSRC}/$$files ${PREFIX}/share/unicornscan/ ;\
	done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
