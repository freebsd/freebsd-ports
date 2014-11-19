# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	1.8.0
CATEGORIES=	ukrainian textproc
MASTER_SITES=	SF/ispell-uk/spell-uk/${PORTVERSION}
DISTNAME=	spell-uk-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ukrainian thesaurus

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	dual

USES=		perl5 tar:tgz
USE_PERL5=	build

PLIST_FILES=	%%DATADIR%%/th_uk_UA.dat \
		%%DATADIR%%/th_uk_UA.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-build:
	@${PERL} ${WRKSRC}/bin/th_gen_idx.pl < ${WRKSRC}/src/thesaurus/th_uk_UA.dat > ${WRKSRC}/src/thesaurus/th_uk_UA.idx

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/src/thesaurus/th_uk_UA.dat ${WRKSRC}/src/thesaurus/th_uk_UA.idx ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
