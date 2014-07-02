# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=		xmltex
PORTVERSION=		1.9
PORTREVISION=	10
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.ctan.org/tex-archive/%SUBDIR%/ \
			${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/xmltex/base
DISTFILES=		${DOC_FILES} ${CLASS_FILES}
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=		non-validating XML parser, written in TeX

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=		libpng15.so:${PORTSDIR}/graphics/png

USE_TEX=	tex

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR} WEB2CDIR=${WEB2CDIR}

WRKSRC=		${WRKDIR}/base
MAKE_ENV=	TEXMFCNF=${FILESDIR}:${LOCALBASE}/${TEXMFWEB2C}

TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
TEXMFWEB2C=	share/texmf/web2c

DOC_FILES=	manual.html manual.tex manual.xml manual.xsl readme.txt

CLASSDIR=	${TEXMFLOCALDIR}/tex/xmltex
CLASS_FILES=	testascii.cfg testascii.tex testascii.xml \
		testsec.tex testsec.xml \
		xmltex.cfg xmltex.ini xmltex.tex pdfxmltex.ini \
		iso-8859-1.xmt iso-8859-2.xmt koi8-r.xmt \
		sec.xmt tei.xmt utf-16.xmt windows-1250.xmt \
		langtest.tex langtest.xml langtest.xmt mathml2.xmt \
		russiankoi8.xml russianutf8.xml portugeselatin1.xml \
		englishutf16.xml englishutf8.xml

WEB2CDIR=	${TEXMFLOCALDIR}/web2c
WEB2C_FILES=	xmltex.fmt pdfxmltex.fmt

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${WEB2CDIR}
	${INSTALL_DATA} ${WEB2C_FILES:S@^@${WRKSRC}/@} ${STAGEDIR}${PREFIX}/${WEB2CDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${STAGEDIR}${DOCSDIR}

post-install:
	${LN} -s -f ${LOCALBASE}/bin/latex ${STAGEDIR}${PREFIX}/bin/xmltex

.include <bsd.port.mk>
