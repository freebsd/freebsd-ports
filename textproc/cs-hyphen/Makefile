# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	SF/aoo-extensions/1078/0/
PKGNAMEPREFIX=	cs-
DISTNAME=	dict-cs-${PORTVERSION}
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Czech hyphenation rules

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_cs_CZ.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_cs_CZ.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
