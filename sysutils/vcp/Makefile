# ex:ts=8
# Ports collection makefile for:  vcp
# Date created:                Tue Feb 11, 2003
# Whom:                        Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	vcp
PORTVERSION=	1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://members.optusnet.com.au/~dbbryan/vcp/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Copy files in curses interface

MAN1=		${PORTNAME}.1

LDFLAGS+=	-lncurses

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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/.vcp.sample ${PREFIX}/etc/vcp.sample
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
