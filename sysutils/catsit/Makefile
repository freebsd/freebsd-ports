PORTNAME=	catsit
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.causal.agency/catsit/snapshot/

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Process supervisor
WWW=		https://git.causal.agency/catsit/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	MANDIR=${PREFIX}/share/man

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/catsit-timer
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/catsit-watch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/catsitd
	${TOUCH} ${STAGEDIR}${PREFIX}/etc/catsit.conf

.include <bsd.port.mk>
