# New ports collection makefile for:	mup
# Date Created:				Oct 4, 2002
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	mup
PORTVERSION=	4.5
PORTREVISION=	0
CATEGORIES=	print audio
MASTER_SITES=	ftp://ftp.arkkra.com/pub/unix/
DISTFILES=	mup45src.tar.gz mup45doc.tar.gz

MAINTAINER=	darius@dons.net.au
COMMENT=	A shareware program for typesetting music

BUILD_WRKSRC=	${WRKSRC}
NO_WRKSUBDIR=	yes

post-extract:
	${CP} ${FILESDIR}/Makefile ${BUILD_WRKSRC}/Makefile
	${CP} ${FILESDIR}/Makefile.mup ${BUILD_WRKSRC}/mup/Makefile
	${CP} ${FILESDIR}/Makefile.fnt ${BUILD_WRKSRC}/mkmupfnt/Makefile
	${CP} ${FILESDIR}/Makefile.disp ${BUILD_WRKSRC}/mupdisp/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mup/mup ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkmupfnt/mkmupfnt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mupdisp/mupdisp ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mupprnt ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/mup
.if !defined(NOPORTDOCS)
	tar -cf - -C ${WRKSRC} overview.txt register.txt README0 README1 mupfeat.txt faq.txt license.txt uguide uguide.ps | tar -C ${PREFIX}/share/doc/mup -xf -
	${INSTALL_MAN} ${WRKSRC}/mup.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mkmupfnt.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mupdisp.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mupprnt.1 ${PREFIX}/man/man1
.endif

MAN1=	mup.1 mkmupfnt.1 mupdisp.1 mupprnt.1

.include <bsd.port.mk>
