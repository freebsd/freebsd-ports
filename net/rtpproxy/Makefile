PORTNAME=	rtpproxy
PORTVERSION=	3.1.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/sippy/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RTP proxy server for OpenSIPS, Kamailio or Sippy B2BUA
WWW=		https://www.rtpproxy.org/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libg722.so:audio/libg722 \
		libgsm.so:audio/gsm \
		libsndfile.so:audio/libsndfile \
		libbcg729.so:audio/bcg729 \
		libsrtp2.so:net/libsrtp2 \
		libucl.so:textproc/libucl \
		libunwind.so:devel/libunwind \
		libxxhash.so:devel/xxhash

USES=		autoreconf cpe libtool pkgconfig localbase:ldflags ssl

GNU_CONFIGURE=	yes
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

OPTIONS_DEFINE=	LTO
OPTIONS_DEFAULT=	LTO
LTO_CONFIGURE_ENABLE=	lto

.include <bsd.port.pre.mk>

# utility udp_contention requires rdtsc, an x86-only feature
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
PLIST_SUB+=	X86=""
.else
PLIST_SUB+=	X86="@comment "
.endif

post-extract:
	${RM} -r ${WRKSRC}/external/libucl
	${RM} -r ${WRKSRC}/external/xxHash

post-build:
	${SED} 's|%%PREFIX%%|${PREFIX}|g ; s|%%RC_SUBR%%|/etc/rc.subr|g' \
	    ${WRKSRC}/scripts/rtpproxy.in.freebsd > ${WRKDIR}/rtpproxy

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rtpproxy ${STAGEDIR}${PREFIX}/etc/rc.d/rtpproxy

.include <bsd.port.post.mk>
