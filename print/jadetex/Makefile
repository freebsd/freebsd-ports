# New ports collection makefile for:    jadetex
# Date created:         5 December 1998
# Whom:                 Sean Kelly <kelly@ad1440.net>
#
# $FreeBSD$
#

PORTNAME=		jadetex
PORTVERSION=		3.13
PORTREVISION=	3
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jadetex

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A TeX backend for Jade, for typesetting SGML documents

BUILD_DEPENDS=		etex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		etex:${PORTSDIR}/print/teTeX-base

TETEXBASE?=		${LOCALBASE}

MAKE_ENV=		TEXMFCNF=${FILESDIR}:${TETEXBASE}/share/texmf/web2c

MESSAGE=		${PKGDIR}/pkg-message
PKGMESSAGE=		${WRKDIR}/pkg-message

MAN1=			jadetex.1 pdfjadetex.1

pre-patch:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${MESSAGE} > ${PKGMESSAGE}

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=${TETEXBASE}/share/texmf; \
	 ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt $$TEXMFMAIN/web2c; \
	 ${MKDIR} -m 555 $$TEXMFMAIN/tex/jadetex; \
	 ${INSTALL_DATA} dsssl.def jadetex.ltx $$TEXMFMAIN/tex/jadetex; \
	 ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	@${LN} -sf ${PREFIX}/bin/etex ${PREFIX}/bin/jadetex
	@${LN} -sf ${PREFIX}/bin/pdfetex ${PREFIX}/bin/pdfjadetex

post-install: rebuild-tex-database display-message

rebuild-tex-database:
	${LOCALBASE}/bin/mktexlsr

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
