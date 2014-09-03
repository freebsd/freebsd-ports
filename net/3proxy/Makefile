# Created by: tim@relay.nnn.tstu.ru
# $FreeBSD$

PORTNAME=	3proxy
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://3proxy.ru/${PORTVERSION}/ \
		http://security.nnov.ru/soft/3proxy/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Proxy servers set (support HTTP(S), FTP, SOCKS, POP3, TCP & UDP)

LICENSE=	APACHE20 BSD2CLAUSE GPLv2 GPLv3 LGPL21 LGPL3
LICENSE_COMB=	dual

CONFLICTS_INSTALL=	libproxy-[0-9]*

OPTIONS_DEFINE=	DOCS

MAKE_ENV=	PTHREAD_LIBS=-pthread
MAKEFILE=	Makefile.unix
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_RC_SUBR=	3proxy
USES=		tar:tgz

PORTDOCS=	Readme

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|' ${WRKSRC}/${MAKEFILE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/ ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/src/ && ${INSTALL_PROGRAM} 3proxy countersutil dighosts ftppr icqpr msnpr mycrypt pop3p proxy smtpp socks tcppm udppm ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/cfg/ && ${INSTALL_DATA} 3proxy.cfg.sample ${STAGEDIR}${PREFIX}/etc/
	cd ${WRKSRC}/src/ && ${INSTALL_LIB} PCREPlugin.so StringsPlugin.so TrafficPlugin.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.cfg.3 ${STAGEDIR}${PREFIX}/man/man3/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.8 ftppr.8 pop3p.8 proxy.8 socks.8 tcppm.8 udppm.8 ${STAGEDIR}${PREFIX}/man/man8/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
