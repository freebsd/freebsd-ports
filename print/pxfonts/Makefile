# New ports collection makefile for:	pxfonts
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	pxfonts
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	fonts/${PORTNAME}
DISTFILES=	${FONTS_AFM:S%^%afm/%}
DISTFILES+=	${FONTS_TFM:S%^%tfm/%}
DISTFILES+=	${FONTS_VF:S%^%vf/%}
DISTFILES+=	${FONTS_TYPE1:S%^%pfb/%}
DISTFILES+=	${DVIPDFM:S%^%dvipdfm/%}
DISTFILES+=	${DVIPS:S%^%dvips/%}
DISTFILES+=	${LATEX:S%^%input/%}
DISTFILES+=	${PXDOC:S%^%doc/%}
DISTFILES+=	px_patch1.zip
EXTRACT_ONLY=	px_patch1.zip

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Yet another Palatino-style font for LaTeX

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX

DIST_SUBDIR=	${PORTNAME}
USE_ZIP=	YES
EXTRACT_AFTER_ARGS=	-d ${PXPATCHDIR}
NO_BUILD=	YES
PLIST_SUB=	TEXMF=${TEXMF} MKTEXLSR=${MKTEXLSR}

TEXMF=		share/texmf
TEXFONTSDIR=	${PREFIX}/${TEXMF}/fonts
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
PXDIST=		${DISTDIR}/${DIST_SUBDIR}
PXPATCHDIR=	${WRKDIR}/px_patch1

FONTS_AFM=	pxbex.afm pxbexa.afm pxbmia.afm pxbsy.afm pxbsya.afm pxbsyb.afm
FONTS_AFM+=	pxbsyc.afm pxex.afm pxexa.afm pxmia.afm pxsy.afm pxsya.afm
FONTS_AFM+=	pxsyb.afm pxsyc.afm rpcxb.afm rpcxbi.afm rpcxi.afm rpcxr.afm
FONTS_AFM+=	rpxb.afm rpxbi.afm rpxbmi.afm rpxbsc.afm rpxi.afm rpxmi.afm
FONTS_AFM+=	rpxr.afm rpxsc.afm

FONTS_TFM=	p1xb.tfm p1xbi.tfm p1xbsc.tfm p1xbsl.tfm p1xi.tfm p1xr.tfm
FONTS_TFM+=	p1xsc.tfm p1xsl.tfm pcxb.tfm pcxbi.tfm pcxbsl.tfm pcxi.tfm
FONTS_TFM+=	pcxr.tfm pcxsl.tfm pxb.tfm pxbex.tfm pxbexa.tfm pxbi.tfm
FONTS_TFM+=	pxbmi.tfm pxbmi1.tfm pxbmia.tfm pxbsc.tfm pxbsl.tfm pxbsy.tfm
FONTS_TFM+=	pxbsya.tfm pxbsyb.tfm pxbsyc.tfm pxex.tfm pxexa.tfm pxi.tfm
FONTS_TFM+=	pxmi.tfm pxmi1.tfm pxmia.tfm pxr.tfm pxsc.tfm pxsl.tfm pxsy.tfm
FONTS_TFM+=	pxsya.tfm pxsyb.tfm pxsyc.tfm rpcxb.tfm rpcxbi.tfm rpcxbsl.tfm
FONTS_TFM+=	rpcxi.tfm rpcxr.tfm rpcxsl.tfm rpxb.tfm rpxbi.tfm rpxbmi.tfm
FONTS_TFM+=	rpxbsc.tfm rpxbsl.tfm rpxi.tfm rpxmi.tfm rpxpplb.tfm
FONTS_TFM+=	rpxpplbi.tfm rpxpplbo.tfm rpxpplr.tfm rpxpplri.tfm
FONTS_TFM+=	rpxpplro.tfm rpxr.tfm rpxsc.tfm rpxsl.tfm

FONTS_VF=	p1xb.vf p1xbi.vf p1xbsc.vf p1xbsl.vf p1xi.vf p1xr.vf p1xsc.vf
FONTS_VF+=	p1xsl.vf pcxb.vf pcxbi.vf pcxbsl.vf pcxi.vf pcxr.vf pcxsl.vf
FONTS_VF+=	pxb.vf pxbi.vf pxbmi.vf pxbmi1.vf pxbsc.vf pxbsl.vf pxi.vf
FONTS_VF+=	pxmi.vf pxmi1.vf pxr.vf pxsc.vf pxsl.vf

FONTS_TYPE1=	pxbex.pfb pxbexa.pfb pxbmia.pfb pxbsy.pfb pxbsya.pfb
FONTS_TYPE1+=	pxbsyb.pfb pxbsyc.pfb pxex.pfb pxexa.pfb pxmia.pfb
FONTS_TYPE1+=	pxsy.pfb pxsya.pfb pxsyb.pfb pxsyc.pfb rpcxb.pfb
FONTS_TYPE1+=	rpcxbi.pfb rpcxi.pfb rpcxr.pfb rpxb.pfb rpxbi.pfb
FONTS_TYPE1+=	rpxbmi.pfb rpxbsc.pfb rpxi.pfb rpxmi.pfb rpxr.pfb
FONTS_TYPE1+=	rpxsc.pfb

PXDOC=		pxfontsdoc.pdf
PXDOC+=		pxfontsdoc.ps
PXDOC+=		pxfontsdoc.tex
PXDOC+=		pxfontsdocA4.pdf
PXDOC+=		pxfontsdocA4.ps
PXDOC+=		pxfontsdocA4.tex

DVIPDFM=	pxr3.map

DVIPS=		pxr.map pxr1.map pxr2.map

LATEX=		omlpxmi.fd omlpxr.fd omspxr.fd omspxsy.fd omxpxex.fd
LATEX+=		ot1pxr.fd ot1pxss.fd ot1pxtt.fd pxfonts.sty t1pxr.fd
LATEX+=		t1pxss.fd t1pxtt.fd ts1pxr.fd ts1pxss.fd ts1pxtt.fd
LATEX+=		upxexa.fd upxmia.fd upxr.fd upxss.fd upxsya.fd
LATEX+=		upxsyb.fd upxsyc.fd upxtt.fd

do-install:
	for i in afm dvipdfm dvips input pfb tfm vf;\
	do\
	  case $${i} in\
	  afm|tfm|vf)		dest=$${i};;\
	  pfb)			dest=type1;;\
	  dvipdfm|dvips)	dest=../$${i};;\
	  input)		dest=../tex/latex;;\
	  esac;\
	  ${ECHO} "Installing: ${WRKSRC}/$${i} -> ${TEXFONTSDIR}/$${dest}/pxr";\
	  ${MKDIR} ${TEXFONTSDIR}/$${dest}/pxr;\
	  ${INSTALL_DATA} ${PXDIST}/$${i}/* ${TEXFONTSDIR}/$${dest}/pxr;\
	done
	cd ${TEXFONTSDIR}/../dvipdfm/config && ${LN} -s -f ../pxr/pxr3.map .
.for i in ${DVIPS}
	cd ${TEXFONTSDIR}/../dvips/config && ${LN} -s -f ../pxr/${i} .
.endfor
	cd ${PXPATCHDIR} &&\
	  ${INSTALL_DATA} pxmi.tfm pxmi1.tfm ${TEXFONTSDIR}/tfm/pxr; \
	  ${INSTALL_DATA} pxmi.vf pxmi1.vf ${TEXFONTSDIR}/vf/pxr; \
	  ${INSTALL_DATA} pxmi.vpl pxmi1.vpl ${TEXFONTSDIR}/vf/pxr

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for sfx in pdf ps tex
	${INSTALL_MAN} \
	  ${PXDIST}/doc/pxfontsdoc.${sfx} \
	  ${PXDIST}/doc/pxfontsdocA4.${sfx} \
	  ${DOCSDIR}
.endfor
	${INSTALL_MAN} ${PXPATCHDIR}/patch1.txt ${DOCSDIR}
.endif
	${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
