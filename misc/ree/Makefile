# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	ree
PORTVERSION=	1.3
CATEGORIES=	misc
MASTER_SITES=	http://gnu.ethz.ch/linuks.mine.nu/ree/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to dump your ROM extensions

PLIST_FILES=	bin/rom-ree bin/fontdump
PORTDOCS=	readme

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-build:
.for f in ${PORTNAME} fontdump
	${CC} ${CFLAGS} ${WRKSRC}/${f}.c -o ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/rom-${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/fontdump ${STAGEDIR}${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
