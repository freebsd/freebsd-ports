# New ports collection makefile for:	videogen
# Date created:			Mar 30, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	videogen
PORTVERSION=	0.33
CATEGORIES=	sysutils
MASTER_SITES=	http://www.dynaweb.hu/opensource/videogen/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for calculating XFree86 modelines

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		${PORTNAME}.1
PORTDOCS=	BUGS CHANGES README THANKS
PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${LN} -sf ${PORTNAME}.1x ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
