# Created by: tim@relay.nnn.tstu.ru
# $FreeBSD$

PORTNAME=	3proxy
PORTVERSION=	0.7.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
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

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/ ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/src/ && ${INSTALL_PROGRAM} 3proxy countersutil dighosts mycrypt ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/cfg/ && ${INSTALL_DATA} 3proxy.cfg.sample ${STAGEDIR}${PREFIX}/etc/
	cd ${WRKSRC}/src/ && ${INSTALL_LIB} PCREPlugin.so StringsPlugin.so TrafficPlugin.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.cfg.3 ${STAGEDIR}${PREFIX}/man/man3/
	cd ${WRKSRC}/man/ && ${INSTALL_MAN} 3proxy.8 ${STAGEDIR}${PREFIX}/man/man8/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
