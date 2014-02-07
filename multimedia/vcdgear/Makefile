# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vcdgear
PORTVERSION=	1.6d
CATEGORIES=	multimedia
MASTER_SITES=	http://www.vcdgear.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to convert VCDs from cue/bin format to mpeg 

WRKSRC=		${WRKDIR}/vcdgear16
NO_BUILD=	true

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	faq.txt manual.txt whatsnew.txt

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	alpha i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
DISTNAME=	${PORTNAME}16d_i386_freebsd42
.elif ${ARCH} == alpha
DISTNAME=	${PORTNAME}16d_alpha_freebsd41
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear16_static \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
