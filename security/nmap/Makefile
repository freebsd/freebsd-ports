# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	nmap
DISTVERSION=	6.40
PORTREVISION=	3
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/ \
		LOCAL/ohauer

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	ohauer
PATCHFILES=	${PORTNAME}-${PORTVERSION}-r${PATCHREV}.diff.bz2

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Port scanning utility for large networks

# http://nmap.org/book/man-legal.html
# Install the nmap modified license because of
# http://insecure.org/news/download-com-fiasco.html
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake tar:bzip2 dos2unix
GNU_CONFIGURE=	yes
DOS2UNIX_FILES=	nselib/data/packetdecoders.lua

# Upstream revision r32810: nselib, scripts
PATCHREV=	32810

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS IPV6 SSL
OPTIONS_DEFAULT=IPV6 SSL

SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_CONFIGURE_OFF=	--without-openssl
SSL_CFLAGS=		-I${OPENSSLINC}

IPV6_CONFIGURE_OFF=	--with-libpcap=${LOCALBASE}/IPv6

.include <bsd.port.options.mk>

# PR: ports/159376  Workaround if OS is build with WITHOUT_INET6
.if ! ${PORT_OPTIONS:MIPV6}
LIB_DEPENDS+=		libpcap.so:${PORTSDIR}/net/libpcap
.endif

CONFIGURE_ARGS+=--without-localdirs \
		--without-zenmap \
		--without-ndiff \
		--with-libpcre=${LOCALBASE} \
		--with-liblua=included \
		--without-nmap-update

# fix for gcc from ports
.if ${CC} != "cc" && ${CC} !="clang"
GCCLIBDIR_CMDS=	${CC} -print-file-name=libstdc++.so | ${SED} -e 's/libstdc++.so//'
CONFIGURE_ARGS+=LDFLAGS="-L$$(${GCCLIBDIR_CMDS})"
NDCC=	true
.endif

PORTDOCS=	CHANGELOG HACKING

# XXX limit results if we do a grep in the sources!
post-extract:
	@${RM} -rf ${WRKSRC}/mswin32

# reflect new mailing addreses
pre-patch:
	${SED} -i '' -e 's|nmap-dev@insecure.org|dev@nmap.org|g' \
	    ${WRKSRC}/nsock/src/nsock_core.c \
	    ${WRKSRC}/zenmap/share/zenmap/locale/hr/LC_MESSAGES/zenmap.mo

post-configure:
	@${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|" ${WRKSRC}/Makefile

pre-install:
	${FIND} ${WRKSRC} -type f \( -name \*.orig -o -name \*.bak \) -delete

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

# gcc from ports is in use
.if defined(NDCC)
	@${ECHO_MSG} do not forget to adjust libnmap.conf
.endif

.include <bsd.port.mk>
