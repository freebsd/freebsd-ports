# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.6.5
CATEGORIES=	ukrainian textproc
MASTER_SITES=	SF/ispell-uk/spell-uk/${PORTVERSION}
DISTNAME=	spell-uk-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hunspell ukrainian dictionnary

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

WRKSRC=	${WRKDIR}/spell-uk-${PORTVERSION}
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

ALL_TARGET=	myspell

PLIST_FILES=	share/hunspell/uk_UA.aff \
		share/hunspell/uk_UA.dic
PLIST_DIRS=	share/hunspell

do-install:
		@${MKDIR} ${PREFIX}/share/hunspell
		@${INSTALL_DATA} ${WRKSRC}/dist/myspell-uk-${PORTVERSION}/uk_UA.aff \
			${WRKSRC}/dist/myspell-uk-${PORTVERSION}/uk_UA.dic \
			${PREFIX}/share/hunspell/
.include <bsd.port.mk>
