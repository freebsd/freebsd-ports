# New ports collection makefile for:    xmltex
# Date created:         9 May 2002
# Whom:                 Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		xmltex
PORTVERSION=		1.9
PORTREVISION=		1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/xmltex/base
DISTFILES=		${DOC_FILES} ${CLASS_FILES}
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=		A non-validating XML parser, written in TeX

BUILD_DEPENDS=		latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX

.include <bsd.port.pre.mk>

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR} WEB2CDIR=${WEB2CDIR}

WRKSRC=		${WRKDIR}/base
MAKE_ENV=	TEXMFCNF=${FILESDIR}:${PREFIX}/${WEB2CDIR}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
.if exists(${LOCALBASE}/bin/kpsewhich)
TEXMFDIR!=	${LOCALBASE}/bin/kpsewhich -expand-var '$$TEXMFMAIN'
.else
TEXMFDIR=	# empty
.endif
CLASSDIR=	${TEXMFDIR:S,^${PREFIX},,:S,^/,,}/tex/xmltex
WEB2CDIR=	${TEXMFDIR:S,^${PREFIX},,:S,^/,,}/web2c

DOC_FILES=	manual.html manual.tex manual.xml manual.xsl
DOC_FILES+=	readme.txt

CLASS_FILES=	testascii.cfg testascii.tex testascii.xml
CLASS_FILES+=	testsec.tex testsec.xml
CLASS_FILES+=	xmltex.cfg xmltex.ini xmltex.tex pdfxmltex.ini
CLASS_FILES+=	iso-8859-1.xmt iso-8859-2.xmt koi8-r.xmt
CLASS_FILES+=	sec.xmt tei.xmt utf-16.xmt windows-1250.xmt
CLASS_FILES+=	langtest.tex langtest.xml langtest.xmt mathml2.xmt
CLASS_FILES+=	russiankoi8.xml russianutf8.xml portugeselatin1.xml
CLASS_FILES+=	englishutf16.xml englishutf8.xml

WEB2C_FILES=	xmltex.fmt pdfxmltex.fmt

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WEB2C_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${WEB2CDIR}
	${MKDIR} -m 555 ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.post.mk>
