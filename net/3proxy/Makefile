PORTNAME=	3proxy
DISTVERSION=	0.9.5
CATEGORIES=	net

MAINTAINER=	timp87@gmail.com
COMMENT=	Proxy servers set (support HTTP(S), FTP, SOCKS, POP3, TCP & UDP)
WWW=		https://3proxy.ru/

LICENSE=	APACHE20 BSD3CLAUSE GPLv2+ LGPL21+
LICENSE_COMB=	dual

USES=		cpe

USE_GITHUB=	yes
USE_RC_SUBR=	3proxy

MAKEFILE=	Makefile.FreeBSD

PLIST_SUB=	3PROXY_LOGDIR=${3PROXY_LOGDIR} \
		PORTNAME=${PORTNAME}

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

3PROXY_LOGDIR=	/var/log/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%3PROXY_LOGDIR%%|${3PROXY_LOGDIR}|' ${WRKSRC}/cfg/3proxy.cfg.sample
	@${REINPLACE_CMD} -E -e 's| proxy( ?\(8\))| httppr\1|' ${WRKSRC}/man/*
	@${REINPLACE_CMD} -E -e 's|([^P] "?)proxy|\1httppr|' ${WRKSRC}/man/proxy.8
	@${REINPLACE_CMD} -E -e 's|#!/.+|#!${PREFIX}/bin/3proxy|' -e 's|/[^ ]+/3proxy\.cfg|${PREFIX}/etc/3proxy.cfg|' ${WRKSRC}/man/3proxy.8

post-build:
	${MV} ${WRKSRC}/bin/proxy ${WRKSRC}/bin/httppr
	${MV} ${WRKSRC}/man/proxy.8 ${WRKSRC}/man/httppr.8

do-install:
	@${MKDIR} ${STAGEDIR}/${3PROXY_LOGDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/bin/ && ${INSTALL_PROGRAM} 3proxy ftppr mycrypt pop3p httppr smtpp socks tcppm udppm ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/cfg/ && ${INSTALL_DATA} 3proxy.cfg.sample ${STAGEDIR}${PREFIX}/etc/
	cd ${WRKSRC}/bin/ && ${INSTALL_LIB} PCREPlugin.so StringsPlugin.so TrafficPlugin.so pamauth.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.cfg.3 ${STAGEDIR}${PREFIX}/share/man/man3/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.8 ftppr.8 pop3p.8 httppr.8 socks.8 tcppm.8 udppm.8 ${STAGEDIR}${PREFIX}/share/man/man8/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
