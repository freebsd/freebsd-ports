# Created by: hrs
# $FreeBSD$

PORTNAME=	cm-super
PORTVERSION=	0.3.4
PORTREVISION=	5
CATEGORIES=	print x11-fonts
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
#MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
#MASTER_SITE_SUBDIR=	fonts/ps-type1
#DISTNAME=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Computer Modern Font Families in Type 1 Fonts

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes
X11_BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

USES=		zip
USE_TEX=	base texmf infra
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	UPDMAP_SYS="${UPDMAP_SYS}" \
		MAPFILES="${MAPFILES}" \
		MKTEXLSR="${MKTEXLSR}" \
		TEXMFDIR=${TEXMFDIR} \
		MACRODIR=${MACRODIR} \

UPDMAP_SYS=	${LOCALBASE}/bin/updmap-sys --quiet --progname=all
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR=	share/texmf
FONTSDIR=	share/fonts/${PORTNAME}
AFMDIR=		${TEXMFDIR}/fonts/afm/public/${PORTNAME}
TYPE1DIR=	${TEXMFDIR}/fonts/type1/public/${PORTNAME}
DVIPDFMMAPDIR=	${TEXMFDIR}/fonts/map/dvipdfm/${PORTNAME}
DVIPSENCDIR=	${TEXMFDIR}/fonts/enc/dvips/${PORTNAME}
DVIPSMAPDIR=	${TEXMFDIR}/fonts/map/dvips/${PORTNAME}
MACRODIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
MAPFILES=	cm-super-t1.map \
		cm-super-t2a.map \
		cm-super-t2b.map \
		cm-super-t2c.map \
		cm-super-ts1.map \
		cm-super-x2.map

IGNORE=		print/texlive-texmf includes this package

.include <bsd.port.options.mk>

do-build:
.if ${PORT_OPTIONS:MX11}
	${TOUCH} ${WRKSRC}/pfb/fonts.dir
	(cd ${WRKSRC}/pfb; ${LOCALBASE}/bin/type1inst -nolog -quiet)
.else
	@${DO_NADA}
.endif

post-extract:
	${GZIP_CMD} -d ${WRKSRC}/afm/*.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}/afm
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDIR}/fonts/afm/public
	${INSTALL_DATA} ${WRKSRC}/afm/* ${STAGEDIR}${PREFIX}/${FONTSDIR}/afm
	${LN} -s -f ${PREFIX}/${FONTSDIR}/afm \
		${STAGEDIR}${PREFIX}/${AFMDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}/type1
	${INSTALL_DATA} ${WRKSRC}/pfb/* ${STAGEDIR}${PREFIX}/${FONTSDIR}/type1
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDIR}/fonts/type1/public
	${LN} -s -f ${PREFIX}/${FONTSDIR}/type1 \
		${STAGEDIR}${PREFIX}/${TYPE1DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${DVIPSMAPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/dvips/*.map \
		${STAGEDIR}${PREFIX}/${DVIPSMAPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${DVIPSENCDIR}
	${INSTALL_DATA} \
		${WRKSRC}/dvips/*.enc \
		${STAGEDIR}${PREFIX}/${DVIPSENCDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${DVIPDFMMAPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/dvipdfm/*.map \
		${STAGEDIR}${PREFIX}/${DVIPDFMMAPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${MACRODIR}
	${INSTALL_DATA} \
		${WRKSRC}/type1ec.sty \
		${STAGEDIR}${PREFIX}/${MACRODIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/${FONTSDIR}/

.include <bsd.port.mk>
