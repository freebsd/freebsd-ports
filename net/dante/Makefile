# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	dante
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	net security ipv6
MASTER_SITES=	http://www.inet.no/dante/files/ \
		ftp://ftp.inet.no/pub/socks/

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Circuit-level firewall/proxy

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc \
		libsasl2.so:security/cyrus-sasl2

CONFLICTS=	socks5-[0-9]*

USES=		libtool localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-socks-conf=${PREFIX}/etc/socks.conf \
		--with-sockd-conf=${PREFIX}/etc/sockd.conf
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_RC_SUBR=	sockd

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/socks.conf ${STAGEDIR}${PREFIX}/etc/socks.conf.sample
	${INSTALL_DATA} ${WRKSRC}/example/sockd.conf ${STAGEDIR}${PREFIX}/etc/sockd.conf.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/sockd-basic.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/sockd-chaining.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/socks-simple-withoutnameserver.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/socks-simple.conf ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/doc/README* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rfc* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/SOCKS4*.protocol ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/sockd-stat.awk ${STAGEDIR}${DOCSDIR}/contrib/sockd-stat.awk

.include <bsd.port.mk>
