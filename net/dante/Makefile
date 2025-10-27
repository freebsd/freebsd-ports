PORTNAME=	dante
PORTVERSION=	1.4.3
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	http://www.inet.no/dante/files/ \
		ftp://ftp.inet.no/pub/socks/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Circuit-level firewall/proxy
WWW=		https://www.inet.no/dante/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool localbase ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-socks-conf=${PREFIX}/etc/socks.conf \
		--with-sockd-conf=${PREFIX}/etc/sockd.conf
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_RC_SUBR=	sockd

OPTIONS_DEFINE=	DOCS EXAMPLES UPNP
OPTIONS_DEFAULT=	UPNP

UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CONFIGURE_OFF=	--without-upnp

post-patch:
	@${REINPLACE_CMD} -e '/FORTIFY_SOURCE gives error/,+28d' \
		${WRKSRC}/configure

post-install:
.for x in s d
	${INSTALL_DATA} ${WRKSRC}/example/sock${x}.conf \
		${STAGEDIR}${PREFIX}/etc/sock${x}.conf.sample
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/sockd-basic.conf \
		${WRKSRC}/example/sockd-chaining.conf \
		${WRKSRC}/example/socks-simple-withoutnameserver.conf \
		${WRKSRC}/example/socks-simple.conf ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/doc/README* \
		${WRKSRC}/doc/rfc* \
		${WRKSRC}/doc/SOCKS4*.protocol \
		${WRKSRC}/UPGRADE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/sockd-stat.awk \
		${STAGEDIR}${DOCSDIR}/contrib

.include <bsd.port.mk>
