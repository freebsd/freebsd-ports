# New ports collection makefile for:    mpeg_encode
# Date created:
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mpeg_encode
PORTVERSION=	1.5b
CATEGORIES=	multimedia
MASTER_SITES=	http://bmrc.berkeley.edu/ftp/pub/multimedia/mpeg/encode/ \
		ftp://mm-ftp.CS.Berkeley.EDU/pub/multimedia/mpeg/encode/
DISTNAME=	${PKGNAME}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UCB's MPEG-I video stream encoder

MAN1=		mpeg_encode.1

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

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
