# New ports collection makefile for:    bbe
# Date created:                         8 November 2006
# Whom:                                 Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	bbe
PORTVERSION=	0.2.2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}-/${PORTNAME}/${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A sed-like editor for binary files

MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
DOCS=		AUTHORS ChangeLog README
PORTDOCS=	bbe.html ${DOCS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bbe.html ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
