# New ports collection makefile for:	mup
# Date Created:				Oct 4, 2002
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	mup
PORTVERSION=	5.1
CATEGORIES=	print audio
MASTER_SITES=	ftp://ftp.arkkra.com/pub/unix/
DISTFILES=	mup51src.tar.gz mup51doc.tar.gz

MAINTAINER=	darius@dons.net.au
COMMENT=	A shareware program for typesetting music

USE_XLIB=	yes
MAN1=		mup.1 mkmupfnt.1 mupdisp.1 mupprnt.1

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/Makefile.mup ${WRKSRC}/mup/Makefile
	${CP} ${FILESDIR}/Makefile.fnt ${WRKSRC}/mkmupfnt/Makefile
	${CP} ${FILESDIR}/Makefile.disp ${WRKSRC}/mupdisp/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mup/mup ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkmupfnt/mkmupfnt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mupdisp/mupdisp ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mupprnt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/mup.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/mkmupfnt.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/mupdisp.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/mupprnt.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -cf - -C ${WRKSRC}/docs/ overview.txt register.txt README1 mupfeat.txt faq.txt license.txt uguide uguide.ps | ${TAR} -C ${DOCSDIR} -xf -
	${INSTALL_DATA} ${WRKSRC}/README0 ${DOCSDIR}
.endif

.include <bsd.port.mk>
