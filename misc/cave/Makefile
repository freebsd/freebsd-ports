# ex:ts=8
# Ports collection makefile for:	cave
# Date created:			Dec 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cave
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://m-net.arbornet.org/~bjk/cave/download/

MAINTAINER=	ports@FreeBSD.org

MAN1=	cave.1

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

pre-install:
	@${GZIP_CMD} -d ${WRKSRC}/${MAN1}.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
