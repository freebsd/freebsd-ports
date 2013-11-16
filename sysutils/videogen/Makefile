# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	videogen
PORTVERSION=	0.33
CATEGORIES=	sysutils
MASTER_SITES=	http://www.dynaweb.hu/opensource/videogen/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for calculating XFree86 modelines

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

DOCS=		BUGS CHANGES README THANKS

post-extract:
	@${LN} -sf ${PORTNAME}.1x ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
