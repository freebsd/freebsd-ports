# New ports collection makefile for:	zh-CJK
# Date created:		5 Sep 1999
# Whom:			Jing-Tang Keith Jang (keith@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	CJK
PORTVERSION=	4.3.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	cjk-20001003

MAINTAINER=	keith@FreeBSD.org

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		ttf2pk:${PORTSDIR}/print/freetype:build
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_PACKAGE=	"Needs ttf2pk source from FreeType"

USE_GMAKE=	yes
USE_FREETYPE=	yes
WRKSRC=		${WRKDIR}/cjk-current
ARPHICDIR=	${PREFIX}/share/texmf/fonts/truetype/arphic

post-install:
.if !defined(NOPORTDOCS)
	${RM} -fr ${PREFIX}/share/doc/CJK
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/CJK
.endif
	${RM} -fr ${PREFIX}/share/examples/CJK
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/examples/CJK
	@${MKDIR} ${ARPHICDIR}	# Install Arphic fonts
	@${LN} -s ${PREFIX}/share/fonts/TrueType/bkai00mp.ttf ${ARPHICDIR}/arb5_kai.ttf
	@${LN} -s ${PREFIX}/share/fonts/TrueType/bsmi00lp.ttf ${ARPHICDIR}/arb5_sung.ttf
	@${LN} -s ${PREFIX}/share/fonts/TrueType/gbsn00lp.ttf ${ARPHICDIR}/argb_sung.ttf
	@${LN} -s ${PREFIX}/share/fonts/TrueType/gkai00mp.ttf ${ARPHICDIR}/argb_kai.ttf
	@${LN} -s ttf2pk ${PREFIX}/share/texmf/ttf2tfm

MAN1=		bg5conv.1 cef5conv.1 cefconv.1 cefsconv.1 extconv.1 \
		hbf2gf.1 sjisconv.1 ttf2pk.1 ttf2tfm.1

.include <bsd.port.mk>
