PORTNAME=	hunspell
PORTVERSION=	20251001
CATEGORIES=	portuguese textproc
MASTER_SITES=	https://natura.di.uminho.pt/download/sources/Dictionaries/hunspell/:PT \
		https://pt-br.libreoffice.org/assets/Uploads/PT-BR-Documents/VERO/:BR \
		LOCAL/sunpoet/${PORTNAME}:PT,BR
DISTFILES=	hunspell-pt_PT-${PORTVERSION}.tar.gz:PT \
		ptBR-2013-10-30AOC-2.zip:BR
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Portuguese hunspell dictionaries
WWW=		https://natura.di.uminho.pt/wiki/doku.php?id=dicionarios:main #hunspell

# We pick the common one among:
# - pt_PT is licensed under GPLv2, LGPL21 and MPL11.
# - pt_BR is licensed under LGPL3 and MPL.
LICENSE=	MPL11

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/hunspell-pt_PT-${PORTVERSION}

PLIST_FILES=	${DATADIR}/pt_BR.aff \
		${DATADIR}/pt_BR.dic \
		${DATADIR}/pt_PT.aff \
		${DATADIR}/pt_PT.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKDIR}/pt_BR.aff ${WRKDIR}/pt_BR.dic \
		${WRKSRC}/pt_PT.aff ${WRKSRC}/pt_PT.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
