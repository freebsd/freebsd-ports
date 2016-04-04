# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	flog
PORTVERSION=	1.8
CATEGORIES=	sysutils
MASTER_SITES=	http://oss.ezic.com/flog/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small STDIN-to-file logger with support for log rotation

LICENSE=	GPLv2 # version is not specified actually

PORTDOCS=	README
PLIST_FILES=	bin/flog

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s@|O_LARGEFILE@@" ${WRKSRC}/flog.c

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/flog ${WRKSRC}/flog.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flog ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
