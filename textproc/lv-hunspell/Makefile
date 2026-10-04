PORTNAME=	hunspell
PORTVERSION=	1.5.0
CATEGORIES=	textproc
MASTER_SITES=	SOURCEFORGE/openoffice-lv/openoffice-lv/${DISTNAME}/ \
		https://dict.dv.lv/download/
PKGNAMEPREFIX=	lv-
DISTNAME=	lv_LV-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	aldis@berjoza.lv
COMMENT=	Latvian hunspell dictionaries
WWW=		https://dict.dv.lv/download.php?prj=lv

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${DATADIR}/lv_LV.aff \
		${DATADIR}/lv_LV.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/lv_LV.aff ${WRKSRC}/lv_LV.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
