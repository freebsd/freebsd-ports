# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	ukrainian textproc
MASTER_SITES=	SF/ispell-uk/spell-uk/${PORTVERSION}
DISTNAME=	spell-uk-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ukrainian hunspell dictionaries

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

ALL_TARGET=	myspell
NO_ARCH=	yes
USE_PERL5=	build
USES=		gmake iconv:build shebangfix perl5 tar:tgz
SHEBANG_FILES=	bin/*.pl

PLIST_FILES=	%%DATADIR%%/uk_UA.aff \
		%%DATADIR%%/uk_UA.dic

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/true,/usr/bin/true,g" ${WRKSRC}/src/Dictionary/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/dist/my${DISTNAME}/ && ${INSTALL_DATA} uk_UA.aff uk_UA.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
