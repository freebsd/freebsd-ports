# Created by: tim@relay.nnn.tstu.ru
# $FreeBSD$

PORTNAME=	3proxy
PORTVERSION=	0.8.6
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net

MAINTAINER=	timp87@gmail.com
COMMENT=	Proxy servers set (support HTTP(S), FTP, SOCKS, POP3, TCP & UDP)

LICENSE=	APACHE20 BSD2CLAUSE GPLv2 GPLv3 LGPL21 LGPL3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

MAKEFILE=	Makefile.unix
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_RC_SUBR=	3proxy
USE_GITHUB=	yes
GH_ACCOUNT=	z3APA3A

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|' ${WRKSRC}/${MAKEFILE}

post-build:
	${MV} ${WRKSRC}/src/proxy ${WRKSRC}/src/httppr
	${MV} ${WRKSRC}/man/proxy.8 ${WRKSRC}/man/httppr.8

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/ ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/src/ && ${INSTALL_PROGRAM} 3proxy dighosts ftppr icqpr mycrypt pop3p httppr smtpp socks tcppm udppm ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/cfg/ && ${INSTALL_DATA} 3proxy.cfg.sample ${STAGEDIR}${PREFIX}/etc/
	cd ${WRKSRC}/src/ && ${INSTALL_LIB} PCREPlugin.so StringsPlugin.so TrafficPlugin.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.cfg.3 ${STAGEDIR}${PREFIX}/man/man3/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.8 ftppr.8 pop3p.8 httppr.8 socks.8 tcppm.8 udppm.8 ${STAGEDIR}${PREFIX}/man/man8/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
