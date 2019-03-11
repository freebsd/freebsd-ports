# Created by: cpm
# $FreeBSD$

PORTNAME=	alef
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://alef.hagilda.com/
PKGNAMESUFFIX=	-webfont
DISTNAME=	Alef

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free multi-lingual font designed for screens

LICENSE=	OFL11
LICENSE_FILE=	${WRKDIR}/OFL-license.txt

BUILD_DEPENDS=	${LOCALBASE}/bin/mkfontscale:x11-fonts/mkfontscale

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
FONTSDIR=	${PREFIX}/lib/x11/fonts/${PORTNAME}${PKGNAMESUFFIX}
INSTDAT=	fonts.dir fonts.scale

PLIST_SUB=	FONTSDIR="${FONTSDIR}" WWWDIR_REL="${WWWDIR_REL}${PKGNAMESUFFIX}"

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	COMING-SOON.txt readme.txt

post-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKDIR} && ${MV} TTF ${WRKSRC}
	${MV} ${WRKDIR}/--COMING-SOON--.txt ${WRKDIR}/COMING-SOON.txt

pre-install:
	${MKFONTSCL_CMD} ${WRKDIR}/Alef-Webfont
	${MKFONTDIR_CMD} ${WRKDIR}/Alef-Webfont

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}${PKGNAMESUFFIX}
.for f in Alef-bold.html Alef-regular.html stylesheet.css
	${INSTALL_DATA} ${WRKDIR}/Alef-Webfont/${f} ${STAGEDIR}${WWWDIR}${PKGNAMESUFFIX}
.endfor
.for i in eot svg ttf woff
	${MKDIR} ${STAGEDIR}${WWWDIR}${PKGNAMESUFFIX}/${i}
	${INSTALL_DATA} ${WRKDIR}/Alef-Webfont/*.${i} ${STAGEDIR}${WWWDIR}${PKGNAMESUFFIX}/${i}
.endfor
	cd ${WRKDIR}/Alef-Webfont && ${INSTALL_DATA} ${INSTDAT} ${STAGEDIR}${WWWDIR}${PKGNAMESUFFIX}/ttf
	${CP} -pr ${WRKDIR}/Alef-Webfont/specimen_files ${STAGEDIR}${WWWDIR}${PKGNAMESUFFIX}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
