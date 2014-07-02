# Created by: Sean Kelly <kelly@ad1440.net>
# $FreeBSD$

PORTNAME=	jadetex
PORTVERSION=	3.13
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	TeX backend for Jade, for typesetting SGML documents

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USE_TEX=	tex
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	TEXMFCNF=${FILESDIR}:${TEXMFDIR}/web2c

PLIST_SUB=	TEXMFDIR=share/texmf

TEXMFDIR?=	${LOCALBASE}/share/texmf

do-install:
	${MKDIR} ${STAGEDIR}${TEXMFDIR}/web2c
	${MKDIR} ${STAGEDIR}${TEXMFDIR}/tex/jadetex
	cd ${WRKSRC} && \
	  ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt ${STAGEDIR}${TEXMFDIR}/web2c && \
	  ${INSTALL_DATA} dsssl.def jadetex.ltx ${STAGEDIR}${TEXMFDIR}/tex/jadetex && \
	  ${INSTALL_MAN} jadetex.1 pdfjadetex.1 ${STAGEDIR}${PREFIX}/man/man1
	${LN} -sf ${LOCALBASE}/bin/etex ${STAGEDIR}${PREFIX}/bin/jadetex
	${LN} -sf ${LOCALBASE}/bin/pdfetex ${STAGEDIR}${PREFIX}/bin/pdfjadetex

.include <bsd.port.mk>
