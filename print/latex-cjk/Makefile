# New ports collection makefile for:	zh-CJK
# Version required:	4.3.0
# Date created:		5 Sep 1999
# Whom:			J.T. Jang (jtjang@gcn.net.tw)
#
# $FreeBSD$
#

DISTNAME=	zh-CJK-4.3.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.ffii.org/pub/cjk/devel/
DISTFILES=	cjk-current.tar.gz

MAINTAINER=	jtjang@gcn.net.tw

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${X11BASE}/lib/X11/fonts/TrueType/moe_lishu.ttf:${PORTSDIR}/chinese/moettf \
		ttf2pk:${PORTSDIR}/print/freetype:build
LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_PACKAGE=	Interactive

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cjk-current

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/CJK
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/examples/CJK
.endif

MAN1=		bg5conv.1 cef5conv.1 cefconv.1 cefsconv.1 extconv.1 \
		hbf2gf.1 sjisconv.1 thaiconv.1 ttf2pk.1 ttf2tfm.1

.include <bsd.port.mk>
