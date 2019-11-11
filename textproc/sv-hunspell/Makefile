# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2.40
CATEGORIES=	textproc
MASTER_SITES=	https://extensions.libreoffice.org/extensions/swedish-spelling-dictionary-den-stora-svenska-ordlistan/${PORTVERSION}/@@download/file/ \
		LOCAL/sunpoet/${PORTNAME}
PKGNAMEPREFIX=	sv-
DISTNAME=	ooo_swedish_dict_${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish hunspell dictionaries

LICENSE=	LGPL3

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/sv_FI.aff \
		%%DATADIR%%/sv_FI.dic \
		%%DATADIR%%/sv_SE.aff \
		%%DATADIR%%/sv_SE.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/dictionaries/ && ${INSTALL_DATA} sv_FI.aff sv_FI.dic sv_SE.aff sv_SE.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
