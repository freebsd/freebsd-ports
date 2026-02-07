PORTNAME=	vcp
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsdcluster.org/~mich/software/ \
		LOCAL/fuz

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Copy files in curses interface

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		ncurses
CFLAGS+=	-L${NCURSESLIB}

CONFLICTS=	p5-VCP \
		p5-VCP-autrijus

OPTIONS_DEFINE=	DOCS

pre-build:
	@${REINPLACE_CMD} -e 's|/etc/vcp.conf|${PREFIX}/etc/vcp.conf|' ${WRKSRC}/misc.c
	@${REINPLACE_CMD} -e 's|/etc/vcp.conf|${PREFIX}/etc/vcp.conf|g' ${WRKSRC}/vcp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vcp.conf.sample ${STAGEDIR}${PREFIX}/etc
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/pl/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.pl.1 ${STAGEDIR}${PREFIX}/share/man/pl/man1/${PORTNAME}.1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
