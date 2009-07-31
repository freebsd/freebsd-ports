# New ports collection makefile for:    passivetex
# Date created:         9 May 2002
# Whom:                 Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	passivetex
PORTVERSION=	1.24
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://www.tei-c.org/Software/passivetex/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL FO processor, written in TeX

BUILD_DEPENDS=	${LOCALBASE}/${TEXMFLOCAL}/web2c/xmltex.fmt:${PORTSDIR}/print/xmltex \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/passivetex
MAKE_ENV=	TEXMFCNF=${FILESDIR}:${LOCALBASE}/share/texmf/web2c

MESSAGE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

CLASSDIR=	${TEXMFLOCAL}/tex/passivetex
CLASS_FILES=	dummyels.sty fotex.xmt fotex.sty \
		mlnames.sty ucharacters.sty unicode.sty \
		dummyels.sty nomulticol.sty

DOC_FILES=	LICENSE README.passivetex index.html index.xml

TESTDIR=	${DOCSDIR}/test
TEST_FILES=	Makefile chap01.xml chap02.xml chap03.xml chap04.xml \
		check.xsl darkness.fo darkness.pdf darkness.xml darkness.xsl \
		exercise-print.xsl exercise.fo exercise.pdf exercise.xml \
		fezziPic.png fotex.cfg.eg hyperref.cfg \
		mathex.xml mathex.xsl mathml.xsl mathtei.dtd novel.dtd \
		phys332-1.jpg phys332-2.jpg rmsd.xml \
		tei-oucs.dtd tei.sty teimath-print.xsl teimath.aux teimath.fo \
		teimath.log teimath.out teimath.pdf teimath.xml teimath.xsl \
		teimath2.xml teiu5-print.xsl teiu5.fo teiu5.pdf teiu5.xml \
		teixlite.dtd teixml.cfg test1.fot test2.fot

post-patch:
	@${SED} -e 's,%%TEXMFDIR%%,${LOCALBASE}/share/texmf,' \
		${MESSAGE} > ${PKGMESSAGE}

do-install:
	${MKDIR} -m 555 ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
	${MKDIR} ${TESTDIR}
	${INSTALL_DATA} ${TEST_FILES:S@^@${WRKSRC}/test/@} ${TESTDIR}
.endif

post-install:
	${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
