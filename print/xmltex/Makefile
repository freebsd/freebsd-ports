# New ports collection makefile for:    xmltex
# Date created:         9 May 2002
# Whom:                 Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		xmltex
PORTVERSION=		0.8
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_TEX_CTAN} \
			http://www.tei-c.org.uk/Software/passivetex/:xmltex
MASTER_SITE_SUBDIR=	macros/xmltex/base
DISTFILES=		englishutf16.xml englishutf8.xml iso-8859-1.xmt \
			iso-8859-2.xmt koi8-r.xmt langtest.tex langtest.xml \
			langtest.xmt manual.html manual.tex manual.xml \
			manual.xsl mathml2.xmt pdfxmltex.ini \
			portugeselatin1.xml readme.txt russiankoi8.xml \
			russianutf8.xml sec.xmt tei.xmt testascii.cfg \
			testascii.tex testascii.xml testsec.tex testsec.xml \
			utf-16.xmt windows-1250.xmt xmltex.cfg xmltex.ini \
			xmltex.tex:xmltex
DIST_SUBDIR=		xmltex
EXTRACT_ONLY=

MAINTAINER=		nik@FreeBSD.org

BUILD_DEPENDS=		hugelatex:${PORTSDIR}/print/hugelatex
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX

WRKSRC=			${WRKDIR}/base
USE_ZIP=		yes
MAKE_ENV=		TEXMFCNF=${FILESDIR}:${LOCALBASE}/share/texmf/web2c

post-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/* ${WRKSRC}

post-patch: patch-message copy-makefile

copy-makefile:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=$$(kpsewhich -expand-var '$$TEXMFMAIN'); \
	 ${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt $$TEXMFMAIN/web2c;

post-install: rebuild-tex-database

rebuild-tex-database:
	${LOCALBASE}/bin/mktexlsr

.include <bsd.port.mk>
