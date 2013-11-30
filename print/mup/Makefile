# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	mup
PORTVERSION=	5.5
CATEGORIES=	print audio
MASTER_SITES=	ftp://ftp.arkkra.com/pub/unix/
DISTFILES=	mup${PORTVERSION:S/.//}src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A shareware program for typesetting music

MAN1=		mup.1 mkmupfnt.1 mupdisp.1 mupprnt.1
PLIST_FILES=	bin/mkmupfnt bin/mup bin/mupdisp bin/mupprnt
USE_XORG=	x11
MOREDOCS=	docs/README0 docs/overview.txt docs/register.txt\
		docs/mupfeat.txt docs/faq.txt docs/license.txt docs/uguide.ps
PORTDOCS=	*

NO_STAGE=	yes
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
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${PREFIX}/man/man1
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/uguide
	${FIND} ${WRKSRC}/docs/uguide -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/uguide \;
.for f in ${MOREDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
