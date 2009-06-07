# Ports collection makefile for:	zsync
# Date created:			16 Jan 2005
# Whom:				Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	zsync
PORTVERSION=	0.6.1
CATEGORIES=	net
MASTER_SITES=	http://zsync.moria.org.uk/download/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	A file transfer program

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/zsync \
		bin/zsyncmake
BINS=		zsync zsyncmake
PORTDOCS=	COPYING INSTALL NEWS README
MAN1=		zsync.1 \
		zsyncmake.1

do-install:
	${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/doc/,} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
