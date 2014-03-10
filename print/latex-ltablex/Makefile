# $FreeBSD$

PORTNAME=	ltablex
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print
# As of 2012-08-24, some mirrors are returning a tarball with a
# different checksum, so I am mirroring it locally instead.
# MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
# MASTER_SITE_SUBDIR=	macros/latex/contrib
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rakuco/latex
PKGNAMEPREFIX=	latex-
DIST_SUBDIR=	latex

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Combines the features of both the tabularx and longtable packages

USES=		zip
USE_TEX=	latex
NO_BUILD=	YES
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} \
		TEXMFDIR=${TEXMFDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}

CLASS_FILES=	ltablex.sty
PORTDOCS=	ltablex.pdf ltablex.tex

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
