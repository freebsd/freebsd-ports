PORTNAME=	tkinfo
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	misc tk
MASTER_SITES=	http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk script to read GNU "info" files and display them
WWW=		http://math-www.uni-paderborn.de/~axel/tkinfo/

LICENSE=	MIT

USES+=		tk
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/tkinfo \
		share/man/man1/tkinfo.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/info|${LOCALBASE}/info|; \
		 s|exec wish|exec ${WISH}|' ${WRKSRC}/tkinfo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tkinfo.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
