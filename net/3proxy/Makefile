# Created by: tim@relay.nnn.tstu.ru
# $FreeBSD$

PORTNAME=	3proxy
PORTVERSION=	0.8.12
CATEGORIES=	net

MAINTAINER=	timp87@gmail.com
COMMENT=	Proxy servers set (support HTTP(S), FTP, SOCKS, POP3, TCP & UDP)

LICENSE=	APACHE20 BSD3CLAUSE GPLv2+ LGPL21+
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

3PROXY_LOGDIR=	/var/log/${PORTNAME}

MAKEFILE=	Makefile.unix
USE_RC_SUBR=	3proxy
USE_GITHUB=	yes
GH_ACCOUNT=	z3APA3A
PLIST_SUB=	PORTNAME=${PORTNAME} \
		3PROXY_LOGDIR=${3PROXY_LOGDIR}

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|%%3PROXY_LOGDIR%%|${3PROXY_LOGDIR}|' ${WRKSRC}/cfg/3proxy.cfg.sample

post-build:
	${MV} ${WRKSRC}/src/proxy ${WRKSRC}/src/httppr
	${MV} ${WRKSRC}/man/proxy.8 ${WRKSRC}/man/httppr.8

do-install:
	@${MKDIR} ${STAGEDIR}/${3PROXY_LOGDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/src/ && ${INSTALL_PROGRAM} 3proxy dighosts ftppr icqpr mycrypt pop3p httppr smtpp socks tcppm udppm ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/cfg/ && ${INSTALL_DATA} 3proxy.cfg.sample ${STAGEDIR}${PREFIX}/etc/
	cd ${WRKSRC}/src/ && ${INSTALL_LIB} PCREPlugin.so StringsPlugin.so TrafficPlugin.so pamauth.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.cfg.3 ${STAGEDIR}${PREFIX}/man/man3/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.8 ftppr.8 pop3p.8 httppr.8 socks.8 tcppm.8 udppm.8 ${STAGEDIR}${PREFIX}/man/man8/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
