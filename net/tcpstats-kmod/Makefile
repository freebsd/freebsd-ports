PORTNAME=	tcpstats
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	net
PKGNAMESUFFIX=	-kmod

MAINTAINER=	dave.seddon.ca@gmail.com
COMMENT=	Kernel module for system-wide TCP socket statistics
WWW=		https://github.com/randomizedcoder/bsd-xtcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	randomizedcoder
GH_PROJECT=	bsd-xtcp

WRKSRC_SUBDIR=	kmod/tcpstats

PLIST_FILES=	${KMODDIR}/tcpstats.ko \
		share/man/man4/tcpstats.4.gz

OPTIONS_DEFINE=		DTRACE STATS

DTRACE_DESC=	Enable DTrace SDT probes
STATS_DESC=	Enable per-socket statistics counters

DTRACE_CFLAGS=	-DTCPSTATS_DTRACE -DKDTRACE_HOOKS
STATS_CFLAGS=	-DTCPSTATS_STATS

DTRACE_PLIST_FILES=	share/examples/tcpstats/all_probes.d \
			share/examples/tcpstats/fill_time.d \
			share/examples/tcpstats/filter_skip_reasons.d \
			share/examples/tcpstats/read_latency.d \
			share/examples/tcpstats/read_summary.d

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man4
	${INSTALL_MAN} ${WRKSRC}/man/tcpstats.4 ${STAGEDIR}${PREFIX}/share/man/man4/

post-install-DTRACE-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/tcpstats
	${INSTALL_DATA} ${WRKSRC}/dtrace/all_probes.d ${STAGEDIR}${PREFIX}/share/examples/tcpstats/
	${INSTALL_DATA} ${WRKSRC}/dtrace/fill_time.d ${STAGEDIR}${PREFIX}/share/examples/tcpstats/
	${INSTALL_DATA} ${WRKSRC}/dtrace/filter_skip_reasons.d ${STAGEDIR}${PREFIX}/share/examples/tcpstats/
	${INSTALL_DATA} ${WRKSRC}/dtrace/read_latency.d ${STAGEDIR}${PREFIX}/share/examples/tcpstats/
	${INSTALL_DATA} ${WRKSRC}/dtrace/read_summary.d ${STAGEDIR}${PREFIX}/share/examples/tcpstats/

.include <bsd.port.mk>
