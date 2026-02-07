PORTNAME=	ngrep
DISTVERSION=	1.48.3
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}/v${DISTVERSION}/
DISTNAME=	v${DISTVERSION}%20source%20code
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network grep
WWW=		https://ngrep.sourceforge.net/ \
		https://github.com/jpr5/ngrep/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-pcap-restart

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/jpr5-${PORTNAME}-c3d586c

PLIST_FILES=	bin/ngrep share/man/man8/ngrep.8.gz
PORTDOCS=	CREDITS EXAMPLES.md INSTALL README.md

OPTIONS_DEFINE=		CAPSICUM DOCS IPV6 PCRE PORTS_PCAP
OPTIONS_DEFAULT=	CAPSICUM PCRE

CAPSICUM_DESC=		Build with capsicum if kernel supports it
PCRE_DESC=		Use PCRE2 instead of GNU regex
PORTS_PCAP_DESC=	Use ports PCAP instead of system PCAP

CAPSICUM_CONFIGURE_ON=	--enable-capsicum

IPV6_CONFIGURE_ENABLE=	ipv6

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
			libpcre2-posix.so:devel/pcre2
PCRE_CONFIGURE_ENABLE=	pcre2

PORTS_PCAP_BUILD_DEPENDS=	${LOCALBASE}/include/pcap.h:net/libpcap
PORTS_PCAP_LIB_DEPENDS=		libpcap.so:net/libpcap
PORTS_PCAP_CONFIGURE_ON=	--with-pcap-includes=${LOCALBASE}/include
PORTS_PCAP_CONFIGURE_OFF=	--with-pcap-includes=/usr/include

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
