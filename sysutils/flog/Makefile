# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	flog
PORTVERSION=	1.8
CATEGORIES=	sysutils
MASTER_SITES=	http://oss.ezic.com/flog/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A small STDIN-to-file logger with support for log rotation

PORTDOCS=	README

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s@|O_LARGEFILE@@" ${WRKSRC}/flog.c

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/flog ${WRKSRC}/flog.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flog ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
