PORTNAME=	pic2fig
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	XCONTRIB/utilities

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pic format to fig format converter

USES=		tar:Z
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-Wno-return-type
PLIST_FILES=	bin/pic2fig man/man1/pic2fig.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pic2fig ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pic2fig.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
