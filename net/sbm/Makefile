PORTNAME=	sbm
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://dl.2f30.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple bandwidth monitor
WWW=		https://git.2f30.org/sbm/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/sbm \
		bin/sbm-plot \
		bin/sbm-rt-plot \
		share/man/man1/sbm.1.gz

PORTSCOUT=	skipv:0.9 # only Linux related changes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbm ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sbm-plot ${WRKSRC}/sbm-rt-plot \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/sbm.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
