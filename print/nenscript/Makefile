# New ports collection makefile for:	nenscript
# Date created:		10 November 1999
# Whom:			cjm2
#
# $FreeBSD$
#

PORTNAME=	nenscript
PORTVERSION=	1.13.3
CATEGORIES=	print
MASTER_SITES=	http://www.risacher.org/nenscript/ \
		ftp://netsw.org/system/tools/print/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the proprietary enscript program from Adobe Systems

USE_BZIP2=	yes

MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
MAN1=		nenscript.1

.include <bsd.port.pre.mk>

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == "YES"
CFLAGS+=	-DUS_VERSION
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nenscript ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nenscript.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
