# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	nmap
DISTVERSION=	6.40
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/ \
		LOCAL/ohauer

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Port scanning utility for large networks

# http://nmap.org/book/man-legal.html
# Install the nmap modified license because of
# http://insecure.org/news/download-com-fiasco.html
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_LUA=	5.1 5.2
LUA_COMPS=	lua
USE_BZIP2=	yes
USES=		gmake
GNU_CONFIGURE=	yes

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
		--with-liblua=${LOCALBASE} \
		--without-nmap-update

CONFIGURE_ENV=	LUA_INCDIR="${LUA_INCDIR}" LUA_LIBDIR="${LUA_LIBDIR}"

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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

# gcc from ports is in use
.if defined(NDCC)
	@${ECHO_MSG} do not forget to adjust libnmap.conf
.endif

.include <bsd.port.mk>
