# New ports collection makefile for:    jadetex
# Date created:         5 December 1998
# Whom:                 Sean Kelly <kelly@ad1440.net>
#
# $FreeBSD$
#

PORTNAME=		jadetex
PORTVERSION=		3.6
CATEGORIES=		print
MASTER_SITES=		http://www.tug.org/applications/jadetex/

MAINTAINER=		nik

BUILD_DEPENDS=		tex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=		png.4:${PORTSDIR}/graphics/png
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX

MAKE_ENV=		TEXMFCNF=${FILESDIR}:${PREFIX}/share/texmf/web2c
USE_ZIP=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}
MESSAGE=		${WRKDIR}/pkg-message

post-extract:
	@${ECHO} all: default > ${WRKSRC}/Makefile.tmp
	@${SED} -e "s/huge//g" ${WRKSRC}/Makefile >> ${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC} && ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt `kpsewhich -expand-var '$$TEXMFMAIN'`/web2c && ${MKDIR} -m 555 `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex && ${INSTALL_DATA} dsssl.def jadetex.ltx `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex)

post-install:
	${PREFIX}/bin/mktexlsr
	@${SED} -e 's,/usr/local,${PREFIX},' ${PKGMESSAGE} > ${MESSAGE}
	@${CAT} ${MESSAGE}

.include <bsd.port.mk>
