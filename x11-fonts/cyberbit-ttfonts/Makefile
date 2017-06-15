# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cyberbit-ttfonts
PORTVERSION=	2.0.20050220
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://ftp.netscape.com/pub/communicator/extras/fonts/windows/ \
		http://aol-4.vo.llnwd.net/pub/communicator/extras/fonts/windows/ \
		ftp://ftp.netscape.com/pub/communicator/extras/fonts/windows/
DISTFILES=	Cyberbit.ZIP 97CyberBase.Doc 97CyberBit.Doc 97CyberCJK.Doc \
		CYBERBIT.DOC CYBERCJK.DOC READMEfirst.txt ReadMe.htm
DIST_SUBDIR=	cyberbit
EXTRACT_ONLY=	Cyberbit.ZIP

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bitstream Cyberbit is a TrueType font that covers Unicode 2.0

RESTRICTED=	Redistribution not permitted; single user license only.

USES=		fonts zip

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}

PORTDOCS=	97CyberBase.Doc 97CyberBit.Doc 97CyberCJK.Doc \
		CYBERBIT.DOC CYBERCJK.DOC READMEfirst.txt ReadMe.htm

OPTIONS_DEFINE=	DOCS
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Cyberbit.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
