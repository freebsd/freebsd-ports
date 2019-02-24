# $FreeBSD$

PORTNAME=	parpd
DISTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.iks-jena.de/pub/mitarb/lutz/parpd/

MAINTAINER=	lutz@donnerhacke.de
COMMENT=	Proxy-ARP daemon

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz
USE_RC_SUBR=	parpd

NO_TEST=	yes
PLIST_FILES=	sbin/parpd man/man8/parpd.8.gz

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/parpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${INSTALL_WRKSRC}/parpd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
