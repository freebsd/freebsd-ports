# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	3.3.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/rospell/Romanian%20dictionaries/dict-${PORTVERSION}/
PKGNAMEPREFIX=	ro-
DISTNAME=	hyph_ro_RO.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Romanian hyphenation rules

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_ro_RO.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_ro_RO.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
