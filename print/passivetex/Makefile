# New ports collection makefile for:    passivetex
# Date created:         9 May 2002
# Whom:                 Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		passivetex
PORTVERSION=		1.24
CATEGORIES=		print
MASTER_SITES=		http://www.tei-c.org.uk/Software/passivetex/
DISTNAME=		${PORTNAME}
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=		XSL FO processor, written in TeX

BUILD_DEPENDS=		kpsewhich:${PORTSDIR}/print/teTeX \
			${LOCALBASE}/share/texmf/web2c/xmltex.fmt:${PORTSDIR}/print/xmltex

NO_BUILD=		yes
USE_ZIP=		yes
WRKSRC=			${WRKDIR}/passivetex
MAKE_ENV=		TEXMFCNF=${FILESDIR}:${LOCALBASE}/share/texmf/web2c

MESSAGE=		${PKGDIR}/pkg-message
PKGMESSAGE=		${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
.if exists(${LOCALBASE}/bin/kpsewhich)
TEXMFDIR!=	${LOCALBASE}/bin/kpsewhich -expand-var '$$TEXMFMAIN'
.else
TEXMFDIR=	# empty
.endif
CLASSDIR=	${TEXMFDIR:S,^${PREFIX},,:S,^/,,}/tex/passivetex

CLASS_FILES=	dummyels.sty fotex.xmt fotex.sty
CLASS_FILES+=	mlnames.sty ucharacters.sty unicode.sty
CLASS_FILES+=	dummyels.sty nomulticol.sty

DOC_FILES=	LICENSE README.passivetex index.html index.xml

TEST_FILES=	Makefile
TEST_FILES+=	chap01.xml chap02.xml chap03.xml chap04.xml
TEST_FILES+=	check.xsl
TEST_FILES+=	darkness.fo darkness.pdf darkness.xml darkness.xsl
TEST_FILES+=	exercise-print.xsl exercise.fo exercise.pdf exercise.xml
TEST_FILES+=	fezziPic.png fotex.cfg.eg hyperref.cfg
TEST_FILES+=	mathex.xml mathex.xsl mathml.xsl
TEST_FILES+=	mathtei.dtd novel.dtd
TEST_FILES+=	phys332-1.jpg phys332-2.jpg
TEST_FILES+=	rmsd.xml
TEST_FILES+=	tei-oucs.dtd tei.sty teimath-print.xsl teimath.aux teimath.fo
TEST_FILES+=	teimath.log teimath.out teimath.pdf teimath.xml teimath.xsl
TEST_FILES+=	teimath2.xml teiu5-print.xsl teiu5.fo teiu5.pdf teiu5.xml
TEST_FILES+=	teixlite.dtd teixml.cfg test1.fot test2.fot

post-patch:
	@${SED} -e 's,%%TEXMFDIR%%,${TEXMFDIR},' \
		${MESSAGE} > ${PKGMESSAGE}

do-install:
	${MKDIR} -m 555 ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/test
	${INSTALL_DATA} ${TEST_FILES:S@^@${WRKSRC}/test/@} ${DOCSDIR}/test
.endif

post-install: rebuild-tex-database display-message

rebuild-tex-database:
	${MKTEXLSR}

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
