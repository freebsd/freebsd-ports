# New ports collection makefile for:    jadetex
# Version required:     2.3
# Date created:         5 December 1998
# Whom:                 Sean Kelly <kelly@plutotech.com>
#
# $Id: Makefile,v 1.1.1.1 1998/12/08 21:08:28 nik Exp $
#
# When jadetex-2.3 goes mainstream, it will replace jadetex-2.1
# currently in the Comprehensive TeX Archive Network (CTAN).  When
# that happens, we ought to change MASTER_SITES to
# MASTER_SITE_TEX_CTAN, and remove the DISTFILES, EXTRACT_CMD,
# EXTRACT_SUFX, EXTRACT_AFTER_ARGS, and NO_WRKSUBDIR.
#

DISTNAME=		jadetex
CATEGORIES=		print
VERSION=		2.3
PKGNAME=		${DISTNAME}-${VERSION}
MAINTAINER=		kelly@plutotech.com
MASTER_SITES=		http://tug.org/applications/jadetex/
DISTFILES=		Makefile.jadetex jadetex.dtx jadetex.ini jadetex.ins \
			pdfjadetex.ini
DIST_SUBDIR=		jadetex
NO_WRKSUBDIR=   	yes
BUILD_DEPENDS=		tex:${PORTSDIR}/print/teTeX-beta
RUN_DEPENDS=		tex:${PORTSDIR}/print/teTeX-beta
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-fp
EXTRACT_AFTER_ARGS=	.
EXTRACT_SUFX=

post-extract:
	@${ECHO} all: default > ${WRKSRC}/Makefile
	@${SED} -e "s/huge//g" ${WRKSRC}/Makefile.jadetex >> ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC} && ${INSTALL_DATA} jadetex.fmt pdfjadetex.fmt `kpsewhich -expand-var '$$TEXMFMAIN'`/web2c && ${MKDIR} -m 555 `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex && ${INSTALL_DATA} dsssl.def isoents.tex jadetex.ltx `kpsewhich -expand-var '$$TEXMFMAIN'`/tex/jadetex)

post-install:
	${PREFIX}/bin/mktexlsr
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
