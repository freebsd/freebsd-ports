# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	mup
PORTVERSION=	5.5
CATEGORIES=	print audio
MASTER_SITES=	ftp://ftp.arkkra.com/pub/unix/
DISTFILES=	mup${PORTVERSION:S/.//}src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shareware program for typesetting music

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

PLIST_FILES=	bin/mkmupfnt bin/mup bin/mupdisp bin/mupprnt \
		man/man1/mup.1.gz man/man1/mkmupfnt.1.gz \
		man/man1/mupdisp.1.gz man/man1/mupprnt.1.gz
USE_XORG=	x11
MOREDOCS=	docs/README0 docs/overview.txt docs/register.txt\
		docs/mupfeat.txt docs/faq.txt docs/license.txt docs/uguide.ps
PORTDOCS=	*

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/Makefile.mup ${WRKSRC}/mup/Makefile
	${CP} ${FILESDIR}/Makefile.fnt ${WRKSRC}/mkmupfnt/Makefile
	${CP} ${FILESDIR}/Makefile.disp ${WRKSRC}/mupdisp/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mup/mup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkmupfnt/mkmupfnt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mupdisp/mupdisp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mupprnt ${STAGEDIR}${PREFIX}/bin
.for f in mup.1 mkmupfnt.1 mupdisp.1 mupprnt.1
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${STAGEDIR}${PREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/uguide
	${FIND} ${WRKSRC}/docs/uguide -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/uguide \;
	${INSTALL_DATA} ${MOREDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
