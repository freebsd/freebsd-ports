# Created by: Andreas Klemm <andreas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	html2ps
DISTVERSION=	1.0b7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	print www perl5
MASTER_SITES=	http://user.it.uu.se/~jan/ \
		http://fossies.org/unix/www/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	HTML to PostScript converter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	mogrify:${PORTSDIR}/graphics/ImageMagick \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		weblint++:${PORTSDIR}/www/weblint++ \
		paperconf:${PORTSDIR}/print/libpaper

NO_BUILD=	yes
USES=		perl5
USE_GHOSTSCRIPT_RUN=	yes

SUB_FILES=	html2psrc

MAN1=		html2ps.1
MAN5=		html2psrc.5
PLIST_FILES=	bin/html2ps \
		etc/html2psrc \
		%%DATADIR%%/html2ps.html \
		%%DATADIR%%/hyphen.tex
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		's|exec perl|exec ${PERL}| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}| ; \
		 s|%%PREFIX%%|${PREFIX}| ; \
		 s|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/html2ps

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2ps ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/html2psrc ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/html2ps.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2psrc.5 ${MAN5PREFIX}/man/man5
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/html2ps.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hyphen.tex ${DATADIR}

.include <bsd.port.mk>
