# New ports collection makefile for:    jadetex
# Date created:         5 December 1998
# Whom:                 Sean Kelly <kelly@plutotech.com>
#
# $FreeBSD$
#
# When jadetex-2.3 goes mainstream, it will replace jadetex-2.1
# currently in the Comprehensive TeX Archive Network (CTAN).  When
# that happens, we ought to change MASTER_SITES to
# MASTER_SITE_TEX_CTAN, and remove the DISTFILES, EXTRACT_CMD,
# EXTRACT_SUFX, EXTRACT_AFTER_ARGS, and NO_WRKSUBDIR.
#

PORTNAME=		jadetex 
PORTVERSION=		2.3 
CATEGORIES=		print
MASTER_SITES=		http://people.FreeBSD.org/~nik/distfiles/jadetex/
DISTFILES=		Makefile.jadetex jadetex.dtx jadetex.ini jadetex.ins \
			pdfjadetex.ini

MAINTAINER=		kelly@plutotech.com

BUILD_DEPENDS=		tex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX

DIST_SUBDIR=		jadetex
NO_WRKSUBDIR=   	yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-fp
EXTRACT_AFTER_ARGS=	.

post-extract:
	@${ECHO} all: default > ${WRKSRC}/Makefile
	@${SED} -e "s/huge//g" ${WRKSRC}/Makefile.jadetex >> ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC} && ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt `kpsewhich -expand-var '$$TEXMFMAIN'`/web2c && ${MKDIR} -m 555 `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex && ${INSTALL_DATA} dsssl.def isoents.tex jadetex.ltx `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex)

post-install:
	${PREFIX}/bin/mktexlsr
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
