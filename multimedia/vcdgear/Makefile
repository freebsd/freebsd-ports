# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vcdgear
PORTVERSION=	1.6d
CATEGORIES=	multimedia
MASTER_SITES=	http://www.vcdgear.com/files/
DISTNAME=	${PORTNAME}16d_i386_freebsd42

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to convert VCDs from cue/bin format to mpeg

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/vcdgear16
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	faq.txt manual.txt whatsnew.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear16_static \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
