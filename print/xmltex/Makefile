# New ports collection makefile for:    xmltex
# Date created:         9 May 2002
# Whom:                 Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		xmltex
PORTVERSION=		1.9
PORTREVISION=		4
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.ctan.org/tex-archive/%SUBDIR%/ \
			${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/xmltex/base
DISTFILES=		${DOC_FILES} ${CLASS_FILES}
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=		A non-validating XML parser, written in TeX

BUILD_DEPENDS=		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
			${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
			latex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
			${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
			latex:${PORTSDIR}/print/teTeX-base

.include <bsd.port.pre.mk>

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR} WEB2CDIR=${WEB2CDIR}

WRKSRC=		${WRKDIR}/base
MAKE_ENV=	TEXMFCNF=${FILESDIR}:${LOCALBASE}/${TEXMFWEB2C}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
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
	${INSTALL_DATA} ${WEB2C_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${WEB2CDIR}
	${MKDIR} -m 555 ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${LN} -s -f ${LOCALBASE}/bin/latex ${PREFIX}/bin/xmltex
	${MKTEXLSR}

.include <bsd.port.post.mk>
