# Created by: hrs@FreeBSD.org
# $FreeBSD$

PORTNAME=	pgf
PORTVERSION=	2.10
CATEGORIES=	print
MASTER_SITES=	SF/pgf/pgf/version%20${PORTVERSION}
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}_${PORTVERSION}.tds

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for TeX Portable Graphic Format

NO_BUILD=	YES
USES=		zip
USE_TEX=	latex
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} \
		TEXMFDIR=${TEXMFDIR}
PORTDOCS= AUTHORS ChangeLog FILES INSTALL README TODO images licenses	\
		macros pgfmanual.pdf text-en version-for-dvipdfm	\
		version-for-dvipdfmx version-for-dvips			\
		version-for-pdftex version-for-tex4ht version-for-vtex	\
		version-for-xetex

TEXMFDIR=	share/texmf
TEXMFDIR_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFDIR}/tex

NO_STAGE=	yes
do-install:
.for C in generic latex plain
	${MKDIR} ${PREFIX}/${CLASSDIR}/${C}
	${CP} -R ${WRKDIR}/tex/${C}/${PORTNAME} \
		${PREFIX}/${CLASSDIR}/${C}/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${CLASSDIR}/${C}/${PORTNAME}
.endfor
	${MKDIR} ${PREFIX}/${CLASSDIR}/context/third
	${CP} -R ${WRKDIR}/tex/context/third/${PORTNAME} \
		${PREFIX}/${CLASSDIR}/context/third/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${CLASSDIR}/context/third/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKDIR}/doc/generic/pgf/* ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
