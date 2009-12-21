# New ports collection makefile for:    jadetex
# Date created:         5 December 1998
# Whom:                 Sean Kelly <kelly@ad1440.net>
#
# $FreeBSD$
#

PORTNAME=	jadetex
PORTVERSION=	3.13
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A TeX backend for Jade, for typesetting SGML documents

BUILD_DEPENDS=	etex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	etex:${PORTSDIR}/print/teTeX-base

MAKE_ENV=	TEXMFCNF=${FILESDIR}:${TEXMFDIR}/web2c

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
PLIST_SUB=	TEXMFDIR=share/texmf

MAN1=		jadetex.1 pdfjadetex.1

TEXMFDIR?=	${LOCALBASE}/share/texmf

do-install:
	${MKDIR} -m 555 ${TEXMFDIR}/tex/jadetex
	cd ${WRKSRC} && \
	  ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt ${TEXMFDIR}/web2c && \
	  ${INSTALL_DATA} dsssl.def jadetex.ltx ${TEXMFDIR}/tex/jadetex && \
	  ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	${LN} -sf ${LOCALBASE}/bin/etex ${PREFIX}/bin/jadetex
	${LN} -sf ${LOCALBASE}/bin/pdfetex ${PREFIX}/bin/pdfjadetex

post-install: rebuild-tex-database display-message

rebuild-tex-database:
	${LOCALBASE}/bin/mktexlsr ${TEXMFDIR}

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
