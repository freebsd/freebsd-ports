PORTNAME=	xmlindent
PORTVERSION=	0.2.17
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XML stream reformatter
WWW=		https://xmlindent.sourceforge.net

LICENSE=	GPLv2

SOURCES=	error.c indent.c buffer.c main.c

PLIST_FILES=	bin/xmlindent share/man/man1/xmlindent.1.gz

do-build:
	@cd ${WRKSRC}; flex xmlindent.yy
	${CC} ${CFLAGS} ${SOURCES:C/(.*)/${WRKSRC}\/\1/} \
		-o ${WRKSRC}/${PORTNAME} -lfl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
