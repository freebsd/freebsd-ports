# New ports collection makefile for:    jadetex
# Date created:         5 December 1998
# Whom:                 Sean Kelly <kelly@ad1440.net>
#
# $FreeBSD$
#

PORTNAME=		jadetex
PORTVERSION=		3.11
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jadetex

MAINTAINER=		nik

BUILD_DEPENDS=		hugelatex:${PORTSDIR}/print/hugelatex
LIB_DEPENDS=		png.4:${PORTSDIR}/graphics/png
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX

MAKE_ENV=		TEXMFCNF=${FILESDIR}:${PREFIX}/share/texmf/web2c

WRKSRC=			${WRKDIR}/${PORTNAME}
MESSAGE=		${WRKDIR}/pkg-message

post-extract:
	@${ECHO} all: betterdefault > ${WRKSRC}/Makefile.tmp
	@${ECHO} betterdefault: jadetex.fmt pdfjadetex.fmt >> ${WRKSRC}/Makefile.tmp
	@${CAT} ${WRKSRC}/Makefile >> ${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC} && ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt `kpsewhich -expand-var '$$TEXMFMAIN'`/web2c && ${MKDIR} -m 555 `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex && ${INSTALL_DATA} dsssl.def jadetex.ltx `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex)

post-install:
	${PREFIX}/bin/mktexlsr
	@${SED} -e 's,/usr/local,${PREFIX},' ${PKGMESSAGE} > ${MESSAGE}
	@${CAT} ${MESSAGE}

.include <bsd.port.mk>
