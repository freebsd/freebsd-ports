PORTNAME=	mpeg_encode
PORTVERSION=	1.5b
DISTVERSIONSUFFIX=-src
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/ahze

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	UCB's MPEG-I video stream encoder

DEPRECATED=	Upstream is dead and it's buggy, consider using multimedia/ffmpeg
EXPIRATION_DATE=2025-01-31

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@(${GREP} -R -l "malloc.h" ${WRKSRC}/* | \
	    ${XARGS} ${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/")

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg_encode ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/mpeg_encode.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in users-guide.ps template.param
	@${INSTALL_DATA} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
