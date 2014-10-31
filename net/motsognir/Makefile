# $FreeBSD$

PORTNAME=	motsognir
PORTVERSION=	1.0.5
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	mateusz@viste.fr
COMMENT=	Full-featured gopher server without dependencies

LICENSE=	GPLv3

USE_RC_SUBR=	motsognir

PLIST_FILES=	bin/motsognir \
		etc/motsognir.conf \
		man/man8/motsognir.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/motsognir ${STAGEDIR}${PREFIX}/bin/motsognir
	${INSTALL_DATA} ${WRKSRC}/motsognir.conf ${STAGEDIR}${PREFIX}/etc/motsognir.conf
	${INSTALL_MAN} ${WRKSRC}/motsognir.8.gz ${STAGEDIR}${MANPREFIX}/man/man8/motsognir.8.gz

.include <bsd.port.mk>
