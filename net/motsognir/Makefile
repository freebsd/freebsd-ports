# $FreeBSD$

PORTNAME=	motsognir
PORTVERSION=	1.0.12
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	kaltheat@gmail.com
COMMENT=	Full-featured gopher server without dependencies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		tar:xz
USE_RC_SUBR=	motsognir

SUB_FILES=	pkg-message

PLIST_FILES=	bin/motsognir \
		"@sample etc/motsognir.conf.sample" \
		man/man8/motsognir.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/motsognir ${STAGEDIR}${PREFIX}/bin/motsognir
	${INSTALL_DATA} ${WRKSRC}/motsognir.conf ${STAGEDIR}${PREFIX}/etc/motsognir.conf.sample
	${INSTALL_MAN} ${WRKSRC}/motsognir.8.gz ${STAGEDIR}${MANPREFIX}/man/man8/motsognir.8.gz

.include <bsd.port.mk>
