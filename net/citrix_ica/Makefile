# New ports collection makefile for:	Citrix ICA Client
# Version required:     2.80.76
# Date created:         20 Sep 1998
# Whom:                 msmith
#
# $Id$
#

DISTNAME=       linux
PKGNAME=	citrix_ica-2.80
CATEGORIES=	comms
MASTER_SITES=   http://citrix.com/bin/client/ICA/
EXTRACT_SUFX=	.tar.z

MAINTAINER=     msmith@FreeBSD.ORG

RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

DIST_SUBDIR=	citrix_ica
NO_WRKSUBDIR=	Yes
NO_BUILD=       Yes
RESTRICTED=	"License prohibits redistribution"
IS_INTERACTIVE=	"Noisy license agreement ignores stdin"

CDIR=           ${PREFIX}/lib/ICAClient
BINDIR=		${PREFIX}/bin

do-install:
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/response \
		> ${WRKSRC}/response
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x
	cd ${WRKSRC} && ./setupwfc < response
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica

.include <bsd.port.mk>
