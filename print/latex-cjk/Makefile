# New ports collection makefile for:	zh-CJK
# Date created:		5 Sep 1999
# Whom:			Keith Jang (keith@freebsd.sinica.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	CJK
PORTVERSION=	4.3.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTFILES=	cjk-20000127.tar.gz

MAINTAINER=	keith@freebsd.sinica.edu.tw

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${X11BASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		ttf2pk:${PORTSDIR}/print/freetype:build
LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_PACKAGE=	"Needs ttf2pk source from FreeType"

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cjk-current

post-install:
.if !defined(NOPORTDOCS)
	${RM} -fr ${PREFIX}/share/doc/CJK
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/CJK
.endif
	${RM} -fr ${PREFIX}/share/examples/CJK
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/examples/CJK

MAN1=		bg5conv.1 cef5conv.1 cefconv.1 cefsconv.1 extconv.1 \
		hbf2gf.1 sjisconv.1 thaiconv.1 ttf2pk.1 ttf2tfm.1

.include <bsd.port.mk>
