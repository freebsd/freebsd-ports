PORTNAME=	nmap
DISTVERSION=	7.94
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://nmap.org/dist/ \
		LOCAL/ohauer

MAINTAINER?=	cy@FreeBSD.org
COMMENT?=	Port scanning utility for large networks
WWW=		https://nmap.org/

# nmap-6.47 => svn.nmap.org/nmap-releases/nmap-6.47 (r33605)
# https://nmap.org/book/man-legal.html
# Install the nmap modified license because of
# http://insecure.org/news/download-com-fiasco.html
LICENSE=	NPSL
LICENSE_NAME=	Nmap Public Source License
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror pkg-sell
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !defined(MASTERDIR)

USES=		tar:bzip2 gmake cpe

# XXX limit results if we do a grep in the sources!
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/mswin32 \
			--no-same-owner --no-same-permissions

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS NLS PCAP SSH2 SSL
OPTIONS_DEFAULT=NLS SSH2 SSL

PCAP_DESC=		Build with libpcap from nmap
SSH2_DESC=		SSH2 protocol support

NLS_CONFIGURE_ENABLE=	nls
PCAP_CONFIGURE_ON=	--with-libpcap=included
SSH2_CONFIGURE_ON=	--with-libssh2=included
SSH2_CONFIGURE_OFF=	--without-libssh2
SSH2_IMPLIES=		SSL
SSL_USES=		ssl
SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_CONFIGURE_OFF=	--without-openssl
SSL_CFLAGS=		-I${OPENSSLINC}
SSL_VARS=		STRIP_FILES+=ncat

DOCS=	CHANGELOG HACKING
STRIP_FILES+=	nmap nping

CONFIGURE_ARGS+=--without-localdirs \
		--without-zenmap \
		--without-ndiff \
		--with-libpcre=included \
		--with-liblua=included \
		--without-nmap-update

.include <bsd.port.options.mk>

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
