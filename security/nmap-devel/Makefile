PORTNAME=	nmap
PORTVERSION=	7.95.${NMAP_COMMIT_DATE}
CATEGORIES=	security
PKGNAMESUFFIX=	-devel

MAINTAINER?=	cy@FreeBSD.org
COMMENT?=	Port scanning utility for large networks
WWW=		https://nmap.org/

# nmap-6.47 => svn.nmap.org/nmap-releases/nmap-6.47 (r33605)
# https://nmap.org/book/man-legal.html
# Install the nmap modified license because of
# http://insecure.org/news/download-com-fiasco.html
LICENSE=	NPSL
LICENSE_NAME=	Nmap Public Source License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror pkg-sell

.if !defined(MASTERDIR)

LIB_DEPENDS=	libpcre2-16.so:devel/pcre2

USES=		gmake cpe libtool
USE_GITHUB=	yes
GH_TAGNAME=	036714cde
NMAP_COMMIT_DATE=	20240327

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--without-localdirs \
		--without-zenmap \
		--without-ndiff \
		--with-libpcre=${LOCALBASE} \
		--with-liblua=included \
		--without-nmap-update
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=	DOCS NLS PCAP SSH2 SSL
OPTIONS_DEFAULT=NLS SSH2 SSL
OPTIONS_SUB=	yes

PCAP_DESC=		Build with libpcap from nmap
SSH2_DESC=		SSH2 protocol support

NLS_CONFIGURE_ENABLE=	nls
PCAP_CONFIGURE_ON=	--with-libpcap=included
SSH2_IMPLIES=		SSL
SSH2_CONFIGURE_ON=	--with-libssh2=included
SSH2_CONFIGURE_OFF=	--without-libssh2
SSL_USES=		ssl
SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_CONFIGURE_OFF=	--without-openssl
SSL_CFLAGS=		-I${OPENSSLINC}
SSL_VARS=		STRIP_FILES+=ncat

DOCS=	CHANGELOG HACKING
STRIP_FILES+=	nmap nping

.include <bsd.port.options.mk>

# XXX limit results if we do a grep in the sources!
post-extract:
	@${RM} -r ${WRKSRC}/mswin32

.if exists(/usr/lib/libibverbs.a)
# Link with libibverbs is needed by static libpcap
post-patch-PCAP-on:
	@${REINPLACE_CMD} -E -e "s|(PCAP_LIBS=['\"].*)(['\"])$$|\1 -libverbs\2|" \
		${WRKSRC}/configure \
		${WRKSRC}/nping/configure \
		${WRKSRC}/ncat/configure
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|" ${WRKSRC}/Makefile

pre-install:
	${FIND} ${WRKSRC} -type f \( -name \*.orig -o -name \*.bak \) -delete

post-install:
	${STRIP_CMD} ${STRIP_FILES:S|^|${STAGEDIR}${PREFIX}/bin/|}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.endif

.include <bsd.port.mk>
