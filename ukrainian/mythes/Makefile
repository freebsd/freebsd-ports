# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythe
PORTVERSION=	1.6.5
CATEGORIES=	ukrainian textproc
MASTER_SITES=	SF/ispell-uk/spell-uk/${PORTVERSION}
DISTNAME=	spell-uk-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Ukrainian thesaurus

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	dual

USE_PERL5_BUILD=	yes

PLIST_FILES=	share/mythes/th_uk_UA.dat \
		share/mythes/th_uk_UA.idx
PLIST_DIRS=	share/mythes

do-build:
	@${PERL} ${WRKSRC}/bin/th_gen_idx.pl < ${WRKSRC}/src/thesaurus/th_uk_UA.dat > ${WRKSRC}/src/thesaurus/th_uk_UA.idx

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKSRC}/src/thesaurus/th_uk_UA.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
