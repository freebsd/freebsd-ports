# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20161001
CATEGORIES=	portuguese textproc
MASTER_SITES=	http://natura.di.uminho.pt/download/sources/Dictionaries/hunspell/:PT \
		http://www.broffice.org/files/:BR \
		LOCAL/sunpoet/${PORTNAME}:PT,BR
DISTFILES=	hunspell-pt_PT-${PORTVERSION}.tar.gz:PT \
		pt_BR-2012-06-09AOC.zip:BR
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Portuguese hunspell dictionaries

# We pick the common one among:
# - pt_PT is licensed under GPLv2, LGPL21 and MPL.
# - pt_BR is licensed under LGPL3 and MPL.
LICENSE=	MPL

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/hunspell-pt_PT-${PORTVERSION}

PLIST_FILES=	%%DATADIR%%/pt_BR.aff \
		%%DATADIR%%/pt_BR.dic \
		%%DATADIR%%/pt_PT.aff \
		%%DATADIR%%/pt_PT.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKDIR}/pt_BR.aff ${WRKDIR}/pt_BR.dic \
		${WRKSRC}/pt_PT.aff ${WRKSRC}/pt_PT.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
