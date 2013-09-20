# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	vcp
PORTVERSION=	2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Copy files in curses interface

MAN1=		${PORTNAME}.1
CONFLICTS=	p5-VCP-[0-9]* \
		p5-VCP-autrijus-[0-9]*

LDFLAGS+=	-lncurses

NO_STAGE=	yes
pre-build:
	@${REINPLACE_CMD} -e 's|/etc/vcp.conf|${PREFIX}/etc/vcp.conf|' ${WRKSRC}/misc.c
	@${REINPLACE_CMD} -e 's|/etc/vcp.conf|${PREFIX}/etc/vcp.conf|g' ${WRKSRC}/vcp.1

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -c main.c && \
	${CC} ${CFLAGS} -c copyall.c && \
	${CC} ${CFLAGS} -c copy.c && \
	${CC} ${CFLAGS} -c screen.c && \
	${CC} ${CFLAGS} -c log.c && \
	${CC} ${CFLAGS} -c path.c && \
	${CC} ${CFLAGS} -c misc.c && \
	${CC} ${CFLAGS} -c color.c && \
	${CC} ${CFLAGS} -o ${PORTNAME} main.o copyall.o copy.o screen.o log.o path.o misc.o color.o ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/vcp.conf.sample ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
