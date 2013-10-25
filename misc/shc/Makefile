# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shc
PORTVERSION=	3.8.9
CATEGORIES=	misc
MASTER_SITES=	http://www.datsi.fi.upm.es/~frosal/sources/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Generic script compiler

PLIST_FILES=	bin/shc man/man1/shc.1.gz

post-extract:
	@${RM} ${WRKSRC}/shc

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/shc ${WRKSRC}/${PORTNAME}-${PORTVERSION}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
