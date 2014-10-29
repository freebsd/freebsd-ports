# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	dante
PORTVERSION=	1.4.0
CATEGORIES=	net security ipv6
MASTER_SITES=	ftp://ftp.inet.no/pub/socks/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/ \
		ftp://ftp.inet.no/pub/socks/old/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Circuit-level firewall/proxy

LICENSE=	BSD

CONFLICTS=	socks5-[0-9]*

BROKEN_i386=	see PR 192295, requests tweaked sysctls

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-socks-conf=${PREFIX}/etc/socks.conf \
		--with-sockd-conf=${PREFIX}/etc/sockd.conf
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USES=	libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	sockd

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000044
CONFIGURE_ARGS+=	--with-libc=libc.so.7
.endif

.if ${OPSYS} == FreeBSD
FORBIDDEN=	Building on 10+ triggers a nasty bug with unix domain sockets
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/socks.conf ${STAGEDIR}${PREFIX}/etc/socks.conf.sample
	${INSTALL_DATA} ${WRKSRC}/example/sockd.conf ${STAGEDIR}${PREFIX}/etc/sockd.conf.sample
	${INSTALL} -d -m 555 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/sockd-basic.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/sockd-chaining.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/socks-simple-withoutnameserver.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/socks-simple.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL} -d -m 555 ${STAGEDIR}${DOCSDIR}
	${INSTALL} -d -m 555 ${STAGEDIR}${DOCSDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/doc/README* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rfc* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/SOCKS4*.protocol ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/sockd-stat.awk ${STAGEDIR}${DOCSDIR}/contrib/sockd-stat.awk

.include <bsd.port.mk>
