# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2005.03.08
PORTREVISION=	1
CATEGORIES=	ukrainian textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	hyph_uk_UA-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ukrainian hyphenation rules

LICENSE=	LGPL21

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_uk_UA.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_uk_UA.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
