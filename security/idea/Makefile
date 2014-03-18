# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	idea
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.de-moliner.ch/richard/downloads/ \
		CRITICAL
DISTNAME=	${PORTNAME}.V${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line IDEA encryption and decryption utility

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${WRKSRC}/idea.c ${WRKSRC}/idea_cmd.c ${CFLAGS} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_MAN} ${WRKSRC}/manl/idea.l ${STAGEDIR}${PREFIX}/man/manl
	${INSTALL_PROGRAM} -m 0555 ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Examples ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/byte_ord.ps ${WRKSRC}/idea_cmd.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
