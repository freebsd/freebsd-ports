# New ports collection makefile for:    jadetex
# Date created:         5 December 1998
# Whom:                 Sean Kelly <kelly@ad1440.net>
#
# $FreeBSD$
#

PORTNAME=		jadetex
PORTVERSION=		3.13
PORTREVISION=		0
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jadetex

MAINTAINER=		nik@FreeBSD.org
COMMENT=	A TeX backend for Jade, for typesetting SGML documents

BUILD_DEPENDS=		tex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX-base

MAKE_ENV=		TEXMFCNF=${FILESDIR}:${LOCALBASE}/share/texmf/web2c

MESSAGE=		${PKGDIR}/pkg-message
PKGMESSAGE=		${WRKDIR}/pkg-message

MAN1=			jadetex.1 pdfjadetex.1

post-patch: patch-makefile patch-message

patch-makefile:
	@${ECHO_CMD} all: betterdefault > ${WRKSRC}/Makefile.tmp
	@${ECHO_CMD} betterdefault: jadetex.fmt pdfjadetex.fmt >> ${WRKSRC}/Makefile.tmp
	@${CAT} ${WRKSRC}/Makefile >> ${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile

pre-patch:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${MESSAGE} > ${PKGMESSAGE}

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=$$(kpsewhich -expand-var '$$TEXMFMAIN'); \
	 ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt $$TEXMFMAIN/web2c; \
	 ${MKDIR} -m 555 $$TEXMFMAIN/tex/jadetex; \
	 ${INSTALL_DATA} dsssl.def jadetex.ltx $$TEXMFMAIN/tex/jadetex; \
	 ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	@${LN} -sf ${PREFIX}/bin/tex ${PREFIX}/bin/jadetex
	@${LN} -sf ${PREFIX}/bin/pdftex ${PREFIX}/bin/pdfjadetex

post-install: rebuild-tex-database display-message

rebuild-tex-database:
	${LOCALBASE}/bin/mktexlsr

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
