# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	mpeg_encode
PORTVERSION=	1.5b
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/ahze
DISTNAME=	${PKGNAME}-src

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	UCB's MPEG-I video stream encoder

MAN1=		mpeg_encode.1

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@(${GREP} -R -l "malloc.h" ${WRKSRC}/* | \
	    ${XARGS} ${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/")

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg_encode ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/mpeg_encode.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in users-guide.ps template.param
	@${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
