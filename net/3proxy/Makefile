# Created by: tim@relay.nnn.tstu.ru
# $FreeBSD$

PORTNAME=	3proxy
PORTVERSION=	0.9.1
CATEGORIES=	net

MAINTAINER=	timp87@gmail.com
COMMENT=	Proxy servers set (support HTTP(S), FTP, SOCKS, POP3, TCP & UDP)

LICENSE=	APACHE20 BSD3CLAUSE GPLv2+ LGPL21+
LICENSE_COMB=	dual

USE_RC_SUBR=	3proxy
USE_GITHUB=	yes
GH_ACCOUNT=	z3APA3A

MAKEFILE=	Makefile.FreeBSD

PLIST_SUB=	PORTNAME=${PORTNAME} \
		3PROXY_LOGDIR=${3PROXY_LOGDIR}

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

3PROXY_LOGDIR=	/var/log/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|%%3PROXY_LOGDIR%%|${3PROXY_LOGDIR}|' ${WRKSRC}/cfg/3proxy.cfg.sample

post-build:
	${MV} ${WRKSRC}/bin/proxy ${WRKSRC}/bin/httppr
	${MV} ${WRKSRC}/man/proxy.8 ${WRKSRC}/man/httppr.8

do-install:
	@${MKDIR} ${STAGEDIR}/${3PROXY_LOGDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/bin/ && ${INSTALL_PROGRAM} 3proxy ftppr mycrypt pop3p httppr smtpp socks tcppm udppm ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/cfg/ && ${INSTALL_DATA} 3proxy.cfg.sample ${STAGEDIR}${PREFIX}/etc/
	cd ${WRKSRC}/bin/ && ${INSTALL_LIB} PCREPlugin.so StringsPlugin.so TrafficPlugin.so pamauth.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.cfg.3 ${STAGEDIR}${PREFIX}/man/man3/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.8 ftppr.8 pop3p.8 httppr.8 socks.8 tcppm.8 udppm.8 ${STAGEDIR}${PREFIX}/man/man8/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
