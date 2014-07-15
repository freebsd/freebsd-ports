# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyberbit-ttfonts
PORTVERSION=	2.0.20050220
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://ftp.netscape.com/pub/communicator/extras/fonts/windows/ \
		http://aol-4.vo.llnwd.net/pub/communicator/extras/fonts/windows/ \
		ftp://ftp.netscape.com/pub/communicator/extras/fonts/windows/ \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/cyberbit/
DISTFILES=	Cyberbit.ZIP 97CyberBase.Doc 97CyberBit.Doc 97CyberCJK.Doc \
		CYBERBIT.DOC CYBERCJK.DOC READMEfirst.txt ReadMe.htm
DIST_SUBDIR=	cyberbit
EXTRACT_ONLY=	Cyberbit.ZIP

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Bitstream Cyberbit is a TrueType font that covers Unicode 2.0

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

RESTRICTED=	Redistribution not permitted; single user license only.

USES=		zip

FONTDIR=	lib/X11/fonts/Cyberbit
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${PREFIX}/${FONTDIR}

WRKSRC=		${WRKDIR}

PORTDOCS=	97CyberBase.Doc 97CyberBit.Doc 97CyberCJK.Doc \
		CYBERBIT.DOC CYBERCJK.DOC READMEfirst.txt ReadMe.htm

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

MKFONTSCALE=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR=	${LOCALBASE}/bin/mkfontdir

do-build:
	cd ${WRKSRC} && ${MKFONTSCALE} && ${MKFONTDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/Cyberbit.ttf ${STAGEDIR}${PREFIX}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.* ${STAGEDIR}${PREFIX}/${FONTDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
