# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/bgoffice/OpenOffice.org%20Hyphenation%20BG/${PORTVERSION}/
PKGNAMEPREFIX=	bg-
DISTNAME=	OOo-hyph-bg-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Bulgarian hyphenation rules

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

USES=		zip
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/hyph_bg_BG.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_bg_BG.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
