# Created by: David O'Brien (obrien@NUXI.com)

PORTNAME=	nmap
DISTVERSION=	7.91
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://nmap.org/dist/ \
		LOCAL/ohauer

MAINTAINER?=	cy@FreeBSD.org
COMMENT?=	Port scanning utility for large networks

# nmap-6.47 => svn.nmap.org/nmap-releases/nmap-6.47 (r33605)
# https://nmap.org/book/man-legal.html
# Install the nmap modified license because of
# http://insecure.org/news/download-com-fiasco.html
LICENSE=	NPSL
LICENSE_NAME=	Nmap Public Source License
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror pkg-sell
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !defined(MASTERDIR)

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		tar:bzip2 gmake cpe
GNU_CONFIGURE=	yes

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS PCAP SSH2 SSL
OPTIONS_DEFAULT=PCAP SSH2 SSL

PCAP_DESC=		Build with libpcap from nmap
SSH2_DESC=		SSH2 protocol support

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
		--with-libpcre=${LOCALBASE} \
		--with-liblua=included \
		--without-nmap-update

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCAP}
BROKEN_FreeBSD_14=	Conflicts with pcap in base
.endif

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
