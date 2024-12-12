PORTNAME=	xmlindent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.18
CATEGORIES=	textproc

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XML stream reformatter
WWW=		https://xmlindent.sourceforge.net

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	penberg

SOURCES=	error.c indent.c buffer.c main.c

PLIST_FILES=	bin/xmlindent \
		share/man/man1/xmlindent.1.gz

do-build:
	@cd ${WRKSRC}; flex xmlindent.yy
	${CC} ${CFLAGS} ${SOURCES:C/(.*)/${WRKSRC}\/\1/} \
		-o ${WRKSRC}/${PORTNAME} -lfl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
