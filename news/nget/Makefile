# New ports collection makefile for:	nget
# Date created:				20 June 2002
# Whom:					George Sorsby <george@crackpipe.net>
#
# $FreeBSD$
#

PORTNAME=	nget
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nget
DISTNAME=	nget-${PORTVERSION}+uulib

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Auto-resuming command line nntp file grabber

MAN1=		nget.1 ngetlite.1
MANCOMPRESSED=	no
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes

.include <bsd.port.pre.mk>

post-extract:
	${LN} -s nget-${PORTVERSION} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nget ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ngetlite ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nget.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ngetlite.1 ${PREFIX}/man/man1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/nget
	${STRIP_CMD} ${PREFIX}/bin/ngetlite
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
