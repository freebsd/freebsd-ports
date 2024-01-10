PORTNAME=	html2ps
DISTVERSION=	1.0b7
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	print www perl5
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	HTML to PostScript converter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		weblint++:www/weblint++ \
		paperconf:print/libpaper

NO_BUILD=	yes
USES=		ghostscript:run magick:6,run perl5

CONFLICTS_INSTALL=	p5-DocSet # bin/html2ps

SUB_FILES=	html2psrc

PLIST_FILES=	bin/html2ps \
		etc/html2psrc \
		share/man/man1/html2ps.1.gz \
		share/man/man5/html2psrc.5.gz \
		${DATADIR_REL}/html2ps.html \
		${DATADIR_REL}/hyphen.tex

post-patch:
	@${REINPLACE_CMD} -e \
		's|exec perl|exec ${PERL}| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}| ; \
		 s|%%PREFIX%%|${PREFIX}| ; \
		 s|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/html2ps

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2ps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/html2psrc ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/html2ps.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2psrc.5 ${STAGEDIR}${PREFIX}/share/man/man5
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/html2ps.html ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hyphen.tex ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
