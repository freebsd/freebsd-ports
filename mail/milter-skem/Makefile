# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	skem
PORTVERSION=	1.0.1
CATEGORIES=	mail
MASTER_SITES=	http://virtual-estates.net/skem/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Cache earlier sendmail's verdicts for the relays

USES=		tar:bzip2 uidfix

PLIST_FILES=	sbin/skem \
		man/man8/skem.8.gz

OPTIONS_DEFINE=	SKEM_MILTER421 SKEM_NO_CLEANUP SKEM_NO_LOGWATCHER SKEM_NETINET6 SKEM_NETINET
SKEM_MILTER421_DESC=	Sendmail was built with -D_FFR_MILTER_421
SKEM_NO_CLEANUP_DESC=	Omit the auto-cleanup module
SKEM_NO_LOGWATCHER_DESC=	Omit the log-watching module
SKEM_NETINET6_DESC=	Support IPv6 addresses (not tested)
SKEM_NETINET_DESC=	Support IPv4 addresses

OPTIONS_DEFAULT=	SKEM_NETINET

.include <bsd.port.options.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.if ${OSVERSION} >= 700011
EXTRA_PATCHES=  files/timet.patch
.endif

.if defined(PTHREAD_LIBS)
MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif
.if defined(PTHREAD_CFLAGS)
MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
.endif

.for o in ${PORT_OPTIONS:MSKEM_*}
.	if ${PORT_OPTIONS:M$o}
MAKE_ARGS+=	-D$o
.	endif
.endfor

.include <bsd.port.mk>
