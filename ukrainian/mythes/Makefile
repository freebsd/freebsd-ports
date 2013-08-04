# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	ukrainian textproc
MASTER_SITES=	SF/ispell-uk/spell-uk/${PORTVERSION}
DISTNAME=	spell-uk-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ukrainian thesaurus

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	build

PLIST_FILES=	%%DATADIR%%/th_uk_UA.dat \
		%%DATADIR%%/th_uk_UA.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-build:
	@${PERL} ${WRKSRC}/bin/th_gen_idx.pl < ${WRKSRC}/src/thesaurus/th_uk_UA.dat > ${WRKSRC}/src/thesaurus/th_uk_UA.idx

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/src/thesaurus/th_uk_UA.dat ${WRKSRC}/src/thesaurus/th_uk_UA.idx ${DATADIR}/

.include <bsd.port.mk>
