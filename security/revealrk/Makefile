PORTNAME=	revealrk
PORTVERSION=	1.2.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search hidden procs/rootkits from cron with low false positive rate

LICENSE=	GPLv3

BROKEN_FreeBSD_12=	fails to compile: revealrk.c: 'struct xtcpcb' has no member named 'xt_socket'
BROKEN_FreeBSD_13=	fails to compile: revealrk.c: 'struct xtcpcb' has no member named 'xt_socket'
BROKEN_FreeBSD_14=	fails to compile: revealrk.c: 'struct xtcpcb' has no member named 'xt_socket'
DEPRECATED=	Deprecate, marked BROKEN on 12+ in 2018
EXPIRATION_DATE=2022-03-31

PLIST_FILES=	bin/revealrk man/man1/revealrk.1.gz

USES=		scons tar:tgz

.if !empty(PREFIX)
MAKE_ARGS+=    --prefix=${STAGEDIR}${PREFIX}
.else
MAKE_ARGS+=    --prefix=${STAGEDIR}${LOCALBASE}
.endif

.include <bsd.port.mk>
