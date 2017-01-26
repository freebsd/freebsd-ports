# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	skem
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://virtual-estates.net/skem/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Cache earlier sendmail's verdicts for the relays

.if !exists( /usr/include/libmilter/mfapi.h )
BUILD_DEPENDS+=	${LOCALBASE}/include/libmilter/mfapi.h:mail/libmilter
CFLAGS+=	-I${LOCALBASE}/include
.endif

USES=		tar:bzip2 uidfix

PLIST_FILES=	sbin/skem \
		man/man8/skem.8.gz

OPTIONS_DEFINE=	SKEM_NO_CLEANUP SKEM_NO_LOGWATCHER SKEM_NETINET6 SKEM_NETINET
SKEM_NO_CLEANUP_DESC=	Omit the auto-cleanup module
SKEM_NO_LOGWATCHER_DESC=	Omit the log-watching module
SKEM_NETINET6_DESC=	Support IPv6 addresses (not tested)
SKEM_NETINET_DESC=	Support IPv4 addresses

OPTIONS_DEFAULT=	SKEM_NETINET
NO_WRKSUBDIR=	yes

.include <bsd.port.options.mk>

.for o in ${PORT_OPTIONS:MSKEM_*}
.	if ${PORT_OPTIONS:M$o}
MAKE_ARGS+=	-D$o
.	endif
.endfor

post-patch:
	@${REINPLACE_CMD} -E 's/char[[:blank:]]+c;/int c;/' ${WRKSRC}/milter.c

.include <bsd.port.mk>
