# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.7.1
CATEGORIES=	ukrainian textproc
MASTER_SITES=	SF/ispell-uk/spell-uk/${PORTVERSION}
DISTNAME=	spell-uk-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ukrainian hunspell dictionaries

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

ALL_TARGET=	myspell
USE_PERL5=	build
USES=		gmake iconv:build shebangfix perl5
SHEBANG_FILES=	bin/*.pl

PLIST_FILES=	%%DATADIR%%/uk_UA.aff \
		%%DATADIR%%/uk_UA.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/dist/my${DISTNAME}/ && ${INSTALL_DATA} uk_UA.aff uk_UA.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
