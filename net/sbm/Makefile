# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	sbm
PORTVERSION=	0.8
CATEGORIES=	net
MASTER_SITES=	http://dl.2f30.org/releases/

MAINTAINER=	t@tobik.me
COMMENT=	Simple bandwidth monitor

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/sbm \
		bin/sbm-plot \
		bin/sbm-rt-plot \
		man/man1/sbm.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbm ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sbm-plot ${WRKSRC}/sbm-rt-plot \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/sbm.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
