# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	passivetex
PORTVERSION=	1.24
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	http://projects.oucs.ox.ac.uk/passivetex/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL FO processor, written in TeX

NO_BUILD=	yes
USES=		zip
USE_TEX=	tetex xmltex texhash
TEXHASHDIRS=	${TEXMFDIR}
WRKSRC=		${WRKDIR}/passivetex
MAKE_ENV=	TEXMFCNF=${FILESDIR}:${LOCALBASE}/${TEXMFDIR}/web2c
SUB_FILES=	pkg-message
SUB_LIST=	TEXMFDIR=${TEXMFDIR}
PLIST_SUB=	CLASSDIR=${CLASSDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	LICENSE README.passivetex index.html index.xml

PORTEXAMPLES=	Makefile chap01.xml chap02.xml chap03.xml chap04.xml \
		check.xsl darkness.fo darkness.pdf darkness.xml darkness.xsl \
		exercise-print.xsl exercise.fo exercise.pdf exercise.xml \
		fezziPic.png fotex.cfg.eg hyperref.cfg \
		mathex.xml mathex.xsl mathml.xsl mathtei.dtd novel.dtd \
		phys332-1.jpg phys332-2.jpg rmsd.xml \
		tei-oucs.dtd tei.sty teimath-print.xsl teimath.aux teimath.fo \
		teimath.log teimath.out teimath.pdf teimath.xml teimath.xsl \
		teimath2.xml teiu5-print.xsl teiu5.fo teiu5.pdf teiu5.xml \
		teixlite.dtd teixml.cfg test1.fot test2.fot

CLASSDIR=	${TEXMFDIR}/tex/passivetex
CLASS_FILES=	dummyels.sty fotex.xmt fotex.sty \
		mlnames.sty ucharacters.sty unicode.sty \
		dummyels.sty nomulticol.sty

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} -m 555 ${PREFIX}/${CLASSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${CLASS_FILES} ${PREFIX}/${CLASSDIR}
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/test && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
