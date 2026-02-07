PORTNAME=	ngbuddy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	daniel@belltech.it
COMMENT=	rc.d script for management of netgraph networks
WWW=		https://github.com/bellhyve/ngbuddy

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	bellhyve

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ngbuddy ${STAGEDIR}${PREFIX}/etc/rc.d/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/ngbuddy/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/examples
	${INSTALL_DATA} ${WRKSRC}/examples/devfs.rules ${STAGEDIR}${DATADIR}/examples/
	${INSTALL_DATA} ${WRKSRC}/examples/jail_skel.conf ${STAGEDIR}${DATADIR}/examples/
	${INSTALL_MAN} ${WRKSRC}/ngbuddy.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
