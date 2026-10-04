PORTNAME=	hyphen
PORTVERSION=	1.5.0
CATEGORIES=	textproc
MASTER_SITES=	SOURCEFORGE/openoffice-lv/openoffice-lv/${DISTNAME}/ \
		https://dict.dv.lv/download/
PKGNAMEPREFIX=	lv-
DISTNAME=	lv_LV-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	aldis@berjoza.lv
COMMENT=	Latvian hyphenation rules
WWW=		https://dict.dv.lv/download.php?prj=lv

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${DATADIR}/hyph_lv_LV.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_lv_LV.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
