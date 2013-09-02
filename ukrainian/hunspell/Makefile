# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	ukrainian textproc
MASTER_SITES=	SF/ispell-uk/spell-uk/${PORTVERSION}
DISTNAME=	spell-uk-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ukrainian hunspell dictionaries

USES=		iconv:build shebangfix perl5
ALL_TARGET=	myspell
USE_GMAKE=	yes
USE_PERL5=	build
SHEBANG_FILES=	bin/*.pl

PLIST_FILES=	%%DATADIR%%/uk_UA.aff \
		%%DATADIR%%/uk_UA.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	cd ${WRKSRC}/dist/my${DISTNAME}/ && ${INSTALL_DATA} uk_UA.aff uk_UA.dic ${DATADIR}/

.include <bsd.port.mk>
