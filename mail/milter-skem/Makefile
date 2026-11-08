PORTNAME=	skem
PORTVERSION=	1.0.3
CATEGORIES=	mail
MASTER_SITES=	http://virtual-estates.net/skem/

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Cache earlier sendmail's verdicts for the relays
WWW=		http://virtual-estates.net/skem/

LICENSE=	SKEM
LICENSE_NAME=	Skem license
LICENSE_FILE=	${WRKSRC}/LICENSE
# No permission for derived works here -- not without a payment.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:bzip2 uidfix

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=		SKEM_NETINET SKEM_NETINET6 SKEM_NO_CLEANUP \
			SKEM_NO_LOGWATCHER
OPTIONS_DEFAULT=	SKEM_NETINET

SKEM_NETINET6_DESC=		Support IPv6 addresses (not tested)
SKEM_NETINET_DESC=		Support IPv4 addresses
SKEM_NO_CLEANUP_DESC=		Omit the auto-cleanup module
SKEM_NO_LOGWATCHER_DESC=	Omit the log-watching module

.include <bsd.port.options.mk>

# Use the mail/libmilter, if installed -- or if base does not have one.
.if exists(${LOCALBASE}/include/libmilter/mfapi.h) || \
	!exists(/usr/lib/libmilter.so)
USES+=		localbase:ldflags
LIB_DEPENDS+=	libmilter.so:mail/libmilter
.endif

.for o in ${PORT_OPTIONS:MSKEM_*}
. if ${PORT_OPTIONS:M$o}
MAKE_ARGS+=	-D$o
. endif
.endfor
MAKE_ARGS+=	NO_WDATE_TIME=yes

PLIST_FILES=	sbin/skem \
		share/man/man8/skem.8.gz

.include <bsd.port.mk>
